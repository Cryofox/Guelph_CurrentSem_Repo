#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "clouds.h"
#include "graphics.h"
#include "perlin.h"
#include "enemy.h"

#include <sys/time.h>  //Used for Timing Functions

extern float gravity_Force;
#define TRUE   1
#define FALSE  0

extern void SpawnProjectile( float xForce, float yForce, float zForce, float xPos,float yPos,float zPos);

   //This creates a Manager which Manages all spawned Projectiles, the only
   //code that is relevant is CreateManager, and Free, as Apply Gravity, will call
   //on ALL projectiles within ProjectileManager
   enemy** enemy_Manager;

   int enemyCount=  0;

  float rot_Speed=5;
  float time_Elapsed=0;
  float time_Update=5; // How often to give new random points

  float speed=2;

   //A Buffer is needed for sending New-Destroyed blocks to players ?



   //
   void CreateEnemyManager()
   {
      if(enemy_Manager==NULL)
         enemy_Manager =malloc(PLAYER_COUNT * sizeof(enemy));  

       for(int i=0;i<1;i++)
       { 
        //Poll a Random x and z position for Y value
        int x= (int)(rand())% WORLDX;
        int z= (int)(rand())% WORLDZ; 

        int y=0;

        for(y=0; y<50;y++)
        {
          if(world[x][y][z]==0)
            break;
          y++;
        }
        SpawnEnemy((float)x, (float)y, (float)z);
       }
   }
   //
   void DestroyEnemyManager()
   {
      for(int i=0; i<enemyCount;i++)
         free(enemy_Manager[i]);
      free(enemy_Manager);
   }






   // Protien Spawn Projectile
   // Checks if a projectile can be created with xyz force at players condition
   // if capable (less than < max_Projectiles),  
   void SpawnEnemy(float xpos, float ypos, float zpos)
   {
      //Check if Max Projectiles otherwise create one.
      if(enemyCount> PLAYER_COUNT)
      {
         printf("Too Many projectiles are currently Alive");
         return ;
      }
      int id;
      //Find an Unused ID
      for(id=0; id< PLAYER_COUNT;id++)
      {
         int isInUse=0; //False
         for(int i=0;i<enemyCount;i++)
         {
            if(enemy_Manager[i]->id==id)
            {
               isInUse=1;
               break;
            }
         }
         if( isInUse==0)
         {
            break;
         }
      }


      //getViewPosition(&currLoc_X, &currLoc_Y, &currLoc_Z);

      int mass=5;
      //Create the Projectile
      enemy* newEnemy = malloc(sizeof(enemy));


      newEnemy->id = id;
      newEnemy->xPos=xpos;
      newEnemy->yPos=ypos;
      newEnemy->zPos=zpos;
      newEnemy->faceRotation= 0;

      newEnemy->pointX=xpos;
      newEnemy->pointZ=zpos;
      newEnemy->time_LastSpotted=10;
      newEnemy->time_LastShot=0;
      newEnemy->time_LastDodge=0;
      enemy_Manager[enemyCount]= newEnemy;
      enemyCount++;
   }

   //Ideal Values for Velocity = 25 - 30
   void DestroyEnemy(int index)
   {
      hideMob(enemy_Manager[index]->id);

      //Remove at Index and shift towards the left
      for(int i=index;i< enemyCount;i++)
      {
         free(enemy_Manager[i]);
         enemy_Manager[i]=malloc(sizeof(enemy));

         //Duplicate Struct Contents
         if(i+1 < enemyCount)
            *enemy_Manager[i] = *enemy_Manager[(i+1)];
      }
      enemyCount--;
   }

   //This is called for Each Enemy

   //



  //Check if Player and Mob was hit in blast radius
  void Mob_Player_Hit(float x, float y,float z)
  {
    // printf("Checking hits\n");
    for(int i=0;i< enemyCount;i++)
    {
      //Here we Check if the Mob location matches the explosion circle.
      if( (int)enemy_Manager[i]->xPos == (int)x)
        if( (int)enemy_Manager[i]->yPos >= (int)y-1 && (int)enemy_Manager[i]->yPos <= (int)y+1)
          if( (int)enemy_Manager[i]->zPos == (int)z)
{        printf("DIRECT HIT ON MOB!\n");return;}

      if( (int)enemy_Manager[i]->xPos >= (int)x-2 && (int)enemy_Manager[i]->xPos <=(int)x+2)
        if( (int)enemy_Manager[i]->yPos >= (int)y-2 && (int)enemy_Manager[i]->yPos <= (int)y+2)
          if( (int)enemy_Manager[i]->zPos >= (int)z-2 && (int)enemy_Manager[i]->zPos <= (int)z+2)     
            printf("INDIRECT HIT ON MOB!\n");     
    }
    float pX;
    float pY;
    float pZ;
    getViewPosition(&pX, &pY, &pZ);

    pX*=-1;
    pY*=-1;
    pZ*=-1;
    //Here we Check if the Mob location matches the explosion circle.
    if( (int)pX == (int)x )
      if( (int)pY >= (int)y-1 && (int)pY <= (int)y+1)
        if( (int)pZ == (int)z)
        {printf("DIRECT HIT ON PLAYER!\n");return;}

    if( (int)pX >= (int)x-2 && (int)pX <= (int)x+2)
      if( (int)pY >= (int)y-2 && (int)pY <= (int)y+2)
        if( (int)pZ >= (int)z-2 && (int)pZ <= (int)z+2)
          printf("INDIRECT HIT ON Player!\n");  
  }
  

   //This code repositions all current projectile via their current trajectory (force) based upon time.
   //This code also handles any and all collision related to each projectile bounds and cube hitting.

   int isPlayerVisible(enemy* mob)
   {
    // return FALSE;
      //If the Player is beside or in front the...  
    int isVisible=FALSE;

      float pX;
      float pY;
      float pZ;
      getViewPosition(&pX, &pY, &pZ);

      pX*=-1;
      pY*=-1;
      pZ*=-1;

      float xDiff = pX - mob->xPos;
      float yDiff = pY - mob->yPos;     
      float zDiff = pZ - mob->zPos;        


      float direction = atan( (zDiff)/(xDiff));
      direction*= 180/3.14f;

      int Quadrant=0;

      if(xDiff>0)
        {
          if(zDiff>0)
            Quadrant=1;
          else
            { Quadrant=4;
              direction=360+direction;
            }
        }
      else
      {
          if(zDiff>0)
            { Quadrant=2;
              direction=180+direction;
            }
          else
            {Quadrant=3;
              direction+=180;
            }
      }

      float minValue= mob->faceRotation-90;
      float maxValue= mob->faceRotation+90;



      int isInArc=FALSE;
      //If Min Value <0 Shift Right
      float tempDir;
      if(minValue<0)
      {
        tempDir =  direction+ (minValue*-1);
        // printf("Shifting by:%f\n",minValue);
        maxValue+= minValue*-1;
        minValue+= minValue*-1;

        //Perform Calculations here

        tempDir= (float)((int)tempDir%360);

        if(tempDir>minValue && tempDir<maxValue)
          isInArc=TRUE;

      }
      else if(maxValue>360)
      {
        float diff = 360- maxValue;
        maxValue+=diff;
        minValue+=diff;
        tempDir =  direction+ diff;

        if(tempDir>minValue && tempDir<maxValue)
          isInArc=TRUE;
      }
      else
      {
        tempDir =  direction;
        if(tempDir>minValue && tempDir<maxValue)
          isInArc=TRUE;        
      }


      // printf("m=%f\tM=%f\tTD=%f\n", minValue, maxValue, tempDir);
      // printf("Quadrant=%d\n",Quadrant);             
      // printf("MobFace=%f\n", mob->faceRotation);
      // printf("Direction=%f\n", direction);
      // printf("==================\n");

      //Check Angle
      if( isInArc==TRUE)
      {
        // printf("Detected Player within Angle\n");
        //Now to Check if we are within 50
        if(xDiff<50 && yDiff<50 && zDiff <50)
        {
          //Safe check if player is ontop

          //Now to check if we are in LOS = Line of Sight
          //First Normalize the Vector

          //Calc Magnitude
          float magnitude = sqrt((xDiff *xDiff)+(yDiff *yDiff)+(zDiff *zDiff));
          //Normalize each component
          float nX = xDiff/magnitude;
          float nY = yDiff/magnitude;
          float nZ = zDiff/magnitude;         

          //Now we add the components untill we reach the Diff

          float xVal=0;
          float yVal=0;
          float zVal=0;
          if(xDiff>0)
          {
            isVisible=TRUE;
            for(int i=0;xDiff>xVal;i++)
            {
              xVal= (nX*i);
              yVal= (nY*i);
              zVal= (nZ*i);

              if(world[ (int)(xVal+mob->xPos)  ][ (int)(yVal+mob->yPos ) ][ (int)(zVal+mob->zPos) ]!=0)
              {
                // printf("LINE OF SIGHT BLOCKED!\n");
                isVisible=FALSE;
                break;
              }
            }
          }
          else
          {
            isVisible=TRUE;
            for(int i=0;xDiff<xVal;i++)
            {
              xVal= (nX*i);
              yVal= (nY*i);
              zVal= (nZ*i);

              if(world[ (int)(xVal+mob->xPos)  ][ (int)(yVal+mob->yPos ) ][ (int)(zVal+mob->zPos) ]!=0)
              {
                // printf("LINE OF SIGHT BLOCKED!\n");
                isVisible=FALSE;
                break;
              }
            }
          }

        }
      }


      return isVisible;
      
   }

   int test=0;

   int PlayerSHOT=FALSE;




   void Fight_Routine(enemy* mob, float timePassed)
   {
    // printf("Fight Routine_Engaged!\n");
    //Check if Enemy Shot a Ball

    //Shoot at Player
    if(PlayerSHOT==FALSE)
    { 
      // printf("Shooting Projectile!!\n");
      //Only shoot every 5 seconds
      if(mob->time_LastShot<1)
      {
        mob->time_LastShot+=timePassed;
        return;
      }
        mob->time_LastShot=0;

        //This code is mostly the same as A1.C, under glutmouse down
         long double radianAngle = (long double)45 * M_PI/180.0; 
         float projectile_Velocity=30;
      //Soh Cah Toa
         //Calculate Y and Horizontal Force
         double xzForce= (double)(cos(radianAngle)) * projectile_Velocity;
         double yForce = (double)(sin(radianAngle)) * projectile_Velocity;


        //Now to apply our xz force in the direction we are facing
         // float rots= (90-mob->faceRotation);

         // if(rots<0)
         //  rots=360+rots;
         // if(rots>360)
         //  rots-=360;
   
        
               float pX;
      float pY;
      float pZ;
      getViewPosition(&pX, &pY, &pZ);

      pX*=-1;
      pY*=-1;
      pZ*=-1;

      float xDiff = mob->xPos-pX ;
      float yDiff = mob->yPos-pY  ;     
      float zDiff = mob->zPos-pZ ;        


      float direction = atan( (zDiff)/(xDiff));
      direction*= 180/3.14f;


      // direction*=-1;
      float rots=direction;


        if(xDiff>0)
        {
          if(zDiff>0)
           {
            // printf("Quad[1]\n");
            // rots=90-rots;
            //rots*=-1;
            rots=360-rots;
           } // Quadrant=1;
          else
            { 
              // Quadrant=4;
              // printf("Quad[4]\n");
              // rots=-(360-(rots));
              //direction*=-1;
              rots=(180-rots);
            }
        }
        else
        {
            if(zDiff>0)
              { 
                // Quadrant=2;
                // printf("Quad[2]\n");
                //rots=180+rots;
                //rots=90-rots;
                rots*=-1;
              }
            else
              {
                // Quadrant=3;
                // printf("Quad[3]\n");
                rots+=180;
                rots=90-rots;
              }
        }


       

      // rots*=-1;
      // direction=90+direction;
      direction=(90+direction);


      // if(direction<0)
      //   direction+=360;
      // if(direction>360)
      //   direction-=360;

       //  float orientationY=rots;

      // rots=90+rots;
      // rots*=-1;
      float orientationY=rots;

         //X Controls Up/Down Pitch
         //Y Controls Yaw , which is whats needed for XZ force

         //Orientation produces weird results therefore constrain to 360%


         //orientationY = (int) orientationY%360;

         //Since Triangls have a MAX of 90 Degrees Each, the Quadrant this Orientation is in will be needed

         //
         //Q1 = 0-90
         //Q2 = 90-180
         //Q3 = 180-270
         //Q4 = 270-360 (Which is not possible due to Mod, so its technically 270-359)

         //Overlaps do not matter.
         //

         //Mod 90 to get the Quadrant Angle
         radianAngle = ((int)orientationY)%90;


        //This Value also determines the amount of XZ force needed to apply the XZ Force
        //Calculate XForce and ZForce
        radianAngle = (long double)radianAngle * M_PI/180.0; 

        double xForce= (double)(sin(radianAngle)) * xzForce;
        double zForce= (double)(cos(radianAngle)) * xzForce;

        //Now that the angle is set, apply a quick Swap based on what quadrant we are in.

        //Q1 Inverse XZ
        if( (orientationY) <=90)
        {
         float temp = zForce;
         zForce= -xForce;
         xForce= temp;
        }
        //Q2 this is the default orientation quadrant, do nothing.
        else if( (orientationY) <=180)
        {}
        //Q3 X becomes Negative and Z becomes Negative
        else if( (orientationY) <=270)
        {
         ///printf("Quadrant:3\n");
         float temp = xForce;
         xForce= -zForce;
         zForce= temp;
        }   
        //Q4 Z becomes Negative 
        else
        {
         float temp = xForce;
         xForce= -temp;
         zForce= -zForce;     
        }


        //Now we have all the variables to Spawn our projectile
        //But We Don't. Instead we Send the Message to the Server

         float currLoc_X= mob->xPos;
         float currLoc_Y= mob->yPos;
         float currLoc_Z= mob->zPos;


        // printf("Firing Shot!\n");
        // printf("Force[%f][%f][%f]\n",xForce,yForce,zForce);
        // printf("At[%f][%f][%f]\n",currLoc_X,currLoc_Y,currLoc_Z);      
        SpawnProjectile(xForce,yForce,zForce, currLoc_X, currLoc_Y, currLoc_Z);

    }
    else
    {

      mob->time_LastDodge+=timePassed;
      if(mob->time_LastDodge>1)//If we dodged for 3 Seconds, we can stop dodging
        {
          PlayerSHOT=FALSE;
          mob->time_LastDodge=0;
        }
      //Dodge bullet by walking right
      float speedV = speed*timePassed;
      float x= mob->xPos+ ((speedV) );

      float y= mob->yPos;
      float z= mob->zPos;

      //Get Player position


      //Move Right Box Collision Checking
        if( (world[(int)(x+0.25)][(int)(y)][(int)z]!=0)   ||
            (world[(int)(x-0.25)][(int)(y)][(int)z]!=0)   ||
            (world[(int)(x)][(int)(y)][(int)(z+0.25)]!=0) ||
            (world[(int)(x)][(int)(y)][(int)(z-0.25)]!=0)
          )
        {
         // printf("Entered IF\n");
        //Climbing
          if( (world[(int)(x+0.25)][(int)(y+1)][(int)z]==0)    ||
              (world[(int)(x-0.25)][(int)(y+1)][(int)z]==0)   ||
              (world[(int)(x)][(int)(y+1)][(int)(z+0.25)]==0) ||
              (world[(int)(x)][(int)(y+1)][(int)(z-0.25)]==0)
            )
            {  
              float cX;
              float cY;
              float cZ;

              getViewPosition(&cX, &cY, &cZ);
              cX*=-1;
              cY*=-1;
              cZ*=-1;
              //Dont walk into the player
              if(!((int)cX==(int)x && (int)cY==(int)y &&(int)cZ==(int)z))
              {
                y+=1;
                mob->xPos=x;
                mob->zPos=z;      
              }      
            }
        }

        //Walking
        else
        {
          float cX;
          float cY;
          float cZ;

          getViewPosition(&cX, &cY, &cZ);
          cX*=-1;
          cY*=-1;
          cZ*=-1;
          //Dont walk into the player
          if(!((int)cX==(int)x && (int)cY==(int)y && (int)cZ==(int)z))
          {
          mob->xPos=x;
          mob->zPos=z;  
          }
        }
        mob->yPos=y;
         float rots=mob->faceRotation;

         rots=90-rots;

         if(rots<0)
          rots=360+rots;
         if(rots>360)
          rots-=360;
        // printf("Dodging Projectile!!\n");
        createPlayer(mob->id,mob->xPos,mob->yPos,mob->zPos,(rots));
    }
   }



   //Shoot a Projectile with preset params Angle and Velocity











  void UpdateEnemies(double timePassed)
  {
      time_Elapsed+=timePassed;

      int isNewPoint =FALSE;

      if(time_Elapsed>time_Update)
      {
        time_Elapsed=0;
        isNewPoint=TRUE;
      }

      for(int i=0;i< enemyCount;i++)
      {
        int   id=enemy_Manager[i]->id;
        float x = enemy_Manager[i]->xPos;
        float y = enemy_Manager[i]->yPos;
        float z = enemy_Manager[i]->zPos;

        //Calculate a random direction to add to RotY
        if(isNewPoint==TRUE)
        {
          enemy_Manager[i]->pointX= (int)(rand())% WORLDX;
          enemy_Manager[i]->pointZ= (int)(rand())% WORLDZ; 
        }

        //Rotate Mob into Direction of Point.


        //Calculate the Difference Vector


        //Apply Similar To Gravity Code
        float gravity = 2;
        gravity*= timePassed;

        //
        //y-= gravity;

        if((world[(int)(x+0.25)][(int)(y-gravity)][(int)z]==0)&&
          ((world[(int)(x-0.25)][(int)(y-gravity)][(int)z]==0)) &&
          (world[(int)(x)][(int)(y-gravity)][(int)(z+0.25)]==0)&&
          ((world[(int)(x)][(int)(y-gravity)][(int)(z-0.25)]==0))
          )
        {
         // y+=1;
         // y=(float)((int)y);  
          y-= gravity;        
        }


        //If we Aren't Falling, Wander
        //Wander Code
        if(enemy_Manager[i]->yPos==y)
        {
          //If its visible
          if(isPlayerVisible(enemy_Manager[i]))
          {
          //We see the Player so Reset the Time since he was Last Seen
            enemy_Manager[i]->time_LastSpotted=0;
            Fight_Routine(enemy_Manager[i], timePassed);
          }
          else
          {enemy_Manager[i]->time_LastSpotted+=timePassed;}

          if(enemy_Manager[i]->time_LastSpotted>3)
            if((enemy_Manager[i]->pointX!= enemy_Manager[i]->xPos)&&
               (enemy_Manager[i]->pointZ!= enemy_Manager[i]->zPos))
            {

                float xDiff = (float)(enemy_Manager[i]->pointX)-x ;
                float zDiff = (float)(enemy_Manager[i]->pointZ)-z ;        

                // xDiff = (xDiff);
                // zDiff = (zDiff); 



                float rotation = atan( (zDiff)/(xDiff));
                rotation *= 180/3.14f;


                //Check if they are climbing
                float modif=1;
                if(xDiff<0)
                  modif=-1;

                float speedV = speed*timePassed;
                x+= ((speedV*modif) );

                modif=1;
                if(zDiff<0)
                  modif=-1;      
                z+= ((speedV*modif) );



                if(xDiff>0)
                {
                  if(x > (float)enemy_Manager[i]->pointX)
                    x=enemy_Manager[i]->pointX;
                }
                else
                {
                  if(x < (float)enemy_Manager[i]->pointX)
                    x=enemy_Manager[i]->pointX;
                }

                if(zDiff>0)
                {
                  if(z > (float)enemy_Manager[i]->pointZ)
                    z=enemy_Manager[i]->pointZ;
                }
                else
                {
                  if(z < (float)enemy_Manager[i]->pointZ)
                    z=enemy_Manager[i]->pointZ;
                }      
                
                int Quadrant=0;
                if(xDiff>0)
                {
                  if(zDiff>0)
                    Quadrant=1;
                  else
                    { Quadrant=4;
                      rotation=360+rotation;
                    }
                }
                else
                {
                  if(zDiff>0)
                    { Quadrant=2;
                      rotation=180+rotation;
                    }
                  else
                    {Quadrant=3;
                      rotation+=180;
                    }
                }

                //2 & 4 are wrong
               

                enemy_Manager[i]->faceRotation= rotation; 


                if( (world[(int)(x+0.25)][(int)(y)][(int)z]!=0)   ||
                    (world[(int)(x-0.25)][(int)(y)][(int)z]!=0)   ||
                    (world[(int)(x)][(int)(y)][(int)(z+0.25)]!=0) ||
                    (world[(int)(x)][(int)(y)][(int)(z-0.25)]!=0)
                  )
                {
                 // printf("Entered IF\n");
                //Climbing
                  if( (world[(int)(x+0.25)][(int)(y+1)][(int)z]==0)    ||
                      (world[(int)(x-0.25)][(int)(y+1)][(int)z]==0)   ||
                      (world[(int)(x)][(int)(y+1)][(int)(z+0.25)]==0) ||
                      (world[(int)(x)][(int)(y+1)][(int)(z-0.25)]==0)
                    )
                    {  
                      y+=1;
                      enemy_Manager[i]->xPos=x;
                      enemy_Manager[i]->zPos=z;            
                    }
                }

                //Walking
                else
                {

                  enemy_Manager[i]->xPos=x;
                  enemy_Manager[i]->zPos=z;  
          
                }
          

              }
        }
            enemy_Manager[i]->yPos=y;  
        //printf("-==============-\n");

        //The current graphics/visbility code has weird quadrants setup =_=...
        float rots=enemy_Manager[i]->faceRotation;
         rots=90-rots;

         if(rots<0)
          rots=360+rots;
         if(rots>360)
          rots-=360;


        createPlayer(id,enemy_Manager[i]->xPos,enemy_Manager[i]->yPos,enemy_Manager[i]->zPos,(rots));
      }
  }


















