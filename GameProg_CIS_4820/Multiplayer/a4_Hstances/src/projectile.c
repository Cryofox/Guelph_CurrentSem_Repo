#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "clouds.h"
#include "graphics.h"
#include "perlin.h"
#include "projectile.h"
#include <sys/time.h>  //Used for Timing Functions

extern float gravity_Force;


extern void Mob_Player_Hit(float x, float y,float z);


   //This creates a Manager which Manages all spawned Projectiles, the only
   //code that is relevant is CreateManager, and Free, as Apply Gravity, will call
   //on ALL projectiles within ProjectileManager
   projectile** projectile_Manager;
   int projectile_Count=0;
   int max_Projectiles= 10; // Since projectiles are dependent upon Mobs, that is the projectile Max




   //A Buffer is needed for sending New-Destroyed blocks to players ?



   //
   void CreateProjectileManager()
   {
      if(projectile_Manager==NULL)
         projectile_Manager =malloc( max_Projectiles * sizeof(projectile));  
   }
   //
   void DestroyProjectileManager()
   {
      for(int i=0; i<projectile_Count;i++)
         free(projectile_Manager[i]);
      free(projectile_Manager);
   }
   // Protien Spawn Projectile
   // Checks if a projectile can be created with xyz force at players condition
   // if capable (less than < max_Projectiles),  
   void SpawnProjectile( float xForce, float yForce, float zForce, float xPos,float yPos,float zPos)
   {
      //Check if Max Projectiles otherwise create one.
      if(projectile_Count> max_Projectiles)
      {
         printf("Too Many projectiles are currently Alive");
         return ;
      }
      int id;
      //Find an Unused ID
      for(id=0; id< max_Projectiles;id++)
      {
         int isInUse=0; //False
         for(int i=0;i<projectile_Count;i++)
         {
            if(projectile_Manager[i]->id==id)
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

      float currLoc_X = xPos;
      float currLoc_Y = yPos;
      float currLoc_Z = zPos;

      //getViewPosition(&currLoc_X, &currLoc_Y, &currLoc_Z);

      int mass=5;
      //Create the Projectile
      projectile* newProjectile = malloc(sizeof(projectile));

      newProjectile->id = id;
      newProjectile->xForce= xForce;
      newProjectile->yForce= yForce;
      newProjectile->zForce= zForce;

      newProjectile->xPos=xPos;
      newProjectile->yPos=yPos;
      newProjectile->zPos=zPos;

      //Need to set it directly infront of the view
      newProjectile->mass =mass;
      //Force = Mass * Acceleration, therefore Force/Mass = Acceleration
      newProjectile->acceleration_Downward = -(mass/yForce); //Zero Gravity Acting at this point

      projectile_Manager[projectile_Count]= newProjectile;
      projectile_Count++;
      // printf("Projectile Spawned!\n");

   }

   //Ideal Values for Velocity = 25 - 30
   void DestroyProjectile(int index)
   {
      hideMob(projectile_Manager[index]->id);

      //Remove at Index and shift towards the left
      for(int i=index;i< projectile_Count;i++)
      {
         free(projectile_Manager[i]);
         projectile_Manager[i]=malloc(sizeof(projectile));

         //Duplicate Struct Contents
         if(i+1 < projectile_Count)
            *projectile_Manager[i] = *projectile_Manager[(i+1)];
      }
      projectile_Count--;
   }


   //This code repositions all current projectile via their current trajectory (force) based upon time.
   //This code also handles any and all collision related to each projectile bounds and cube hitting.
  void UpdateProjectiles(double timePassed)
  {
      // printf("ProjectileCount=%d\n",projectile_Count );
      // printf("TE=%f\n",timePassed);
      float gravity = gravity_Force;

      //For Each Particle Check if it has intersected with a bloc
      for(int i=0;i< projectile_Count;i++)    
      {
         //Collision Detect: Bounds, XZ and Ground. The roof is not Counted as a Bound so projectiles can leave and enter the zone
         //if angled correctly.
         if(((projectile_Manager[i]->xPos) > 100 || (projectile_Manager[i]->xPos) <0) || ((projectile_Manager[i]->zPos) > 100 || (projectile_Manager[i]->zPos) <0)) 
            {//printf("D PROJ\n");
              DestroyProjectile(i);}
         else
         {
            //For Legibility
            int xpos =(int)(projectile_Manager[i]->xPos);
            int ypos =(int)(projectile_Manager[i]->yPos);
            int zpos =(int)(projectile_Manager[i]->zPos);

            if(ypos<40)
             { 

              int collision=0;

              //Apply a Box
              float fxPos= projectile_Manager[i]->xPos+0.2;

              if( world[(int)(fxPos)][ypos][zpos]!=0 && world[(int)(fxPos)][ypos][zpos]!=5)
                collision=1;

              fxPos= projectile_Manager[i]->xPos-0.2;
              if( world[(int)(fxPos)][ypos][zpos]!=0 && world[(int)(fxPos)][ypos][zpos]!=5)
                collision=1;

              float fzPos= projectile_Manager[i]->zPos+0.2;

              if( world[xpos][ypos][(int)(fzPos)]!=0 && world[xpos][ypos][(int)(fzPos)]!=5)
                collision=1;
              fzPos= projectile_Manager[i]->zPos-0.2;

              if( world[xpos][ypos][(int)(fzPos)]!=0 && world[xpos][ypos][(int)(fzPos)]!=5)
                collision=1;




                         //Check if the projectile Collides with Anyblock (ANY block)
                         if( collision==1)
                         {
                           //printf("D PROJ\n");
                            //Destroy the Projectile
                            DestroyProjectile(i);
                            //Toggle Off Blocks in 
             
                         //                x
                         //               x x
                         // 1*2       // xxxxx   
                         // 1*1       //  x x    
                         // 1*0       //   x    
             
                          //Print Related Message
                          Mob_Player_Hit(xpos,ypos,zpos);

                        //Apply This in the Direction Up and Down     
                           for(int depth=2; depth>-1;depth--)
                              for(int squareX= xpos-(depth); squareX<= xpos+(depth); squareX++)
                              for(int squareZ= zpos-(depth); squareZ<= zpos+(depth); squareZ++)
                                 //Defensive Coding: Within Array Bounds
                                 if( squareZ >=0 && squareZ<100 && squareX>=0 && squareX<100 && (ypos-depth)>=0 && (ypos-depth)<50)
                                 {  

                                    //Check if the Player is Hit or a Mob

                                    world[squareX][ (ypos- (2-depth))][squareZ]=0; 
                                    world[squareX][ (ypos+ (2-depth))][squareZ]=0;                      
                                 }   
             
                         }

              }
         } 
      }

      //For Each Projectile Toggle it as Alive and show its Current Position
      for(int i=0;i< projectile_Count;i++)
      {
         //The distance travelled is equal to the Force Applied
         //Calculate total Force Applied
         //Heavier Mass = Higher Gravity Usage
         float forceGravity = projectile_Manager[i]->mass * gravity;

         //This will calculate the Vertical Direction the mob is moving in
         float totalUpwardForce = (projectile_Manager[i]->yForce *timePassed) - (forceGravity * timePassed);


         //Calculate new ball Position
         projectile_Manager[i]->xPos += (projectile_Manager[i]->xForce * timePassed);
         projectile_Manager[i]->yPos += totalUpwardForce;
         projectile_Manager[i]->zPos += (projectile_Manager[i]->zForce * timePassed);

         //Since There is no difference between Create/Set mob, other than visibility (which we want)
         createMob(projectile_Manager[i]->id, projectile_Manager[i]->xPos,projectile_Manager[i]->yPos,projectile_Manager[i]->zPos,0 );


         //Decrement yForce as only Gravity is constantly applied
         projectile_Manager[i]->yForce -= (forceGravity * timePassed);
         if(projectile_Manager[i]->yForce<0)
            projectile_Manager[i]->yForce=0;

         //Store this as the remaining upward Force

      }

  }


//Code Called by Server to Send Player List to Players
char* Stringify_Projectiles()
{
  char* string;
  char message[5000]; //This is equal to 500* the max num of players

  char portion[100] ;
         memset(message,0,500);

  //All that is needed
    for(int i=0;i< projectile_Count;i++)
    {

         //X Loc
           snprintf(portion,100,"%f",projectile_Manager[i]->xPos);
           strcat(message,portion);
           strcat(message,",");

           //Y Loc
           snprintf(portion,100,"%f",projectile_Manager[i]->yPos);
           strcat(message,portion);
           strcat(message,",");

           //Z Loc
           snprintf(portion,100,"%f",projectile_Manager[i]->zPos);
           strcat(message,portion);
           strcat(message,"|");

   }
  //This is in case no projectiles are sent
    strcat(message,"}:");
    strcat(message,"\0");
    string=strdup(message);
   // printf("THE STRING IS:%s\n",string);
    return string;
}


void DeStringify_Projectiles(char* stringMsg)
{
  //printf("DESTRING\n");
  //printf("Message=%s\n",stringMsg);
  int I=0;
  //Show the List of CurrentPlayers
    //The Players are Seperated via '|' characters
  char* endToken_1;
  //Seperate the First Player Token Slice
  char* playerToken = strtok_r(stringMsg,"|",&endToken_1);
  int i=0;

  //Continually Slice Players
  while (playerToken !=NULL)
  {
   if(playerToken==NULL)
      goto BadMessage;   
    //printf("NEWPLAYERSTRING\n");
    
   // printf("Projectile:%s\n",playerToken);
      //Take the First 3 Vals for position
    char* copy = strdup(playerToken);

    char* endToken_2;
    char* infoToken = strtok_r(copy,",",&endToken_2);
    
    if(infoToken==NULL)
      goto BadMessage;
    float pX= atof(infoToken);


    infoToken = strtok_r(NULL,",",&endToken_2);
    if(infoToken==NULL)
      goto BadMessage;
    float pY= atof(infoToken);

    infoToken = strtok_r(NULL,",",&endToken_2);
    if(infoToken==NULL)
      goto BadMessage;
    float pZ= atof(infoToken);


    //Same Code as Set Player, just saves the Show Flag
    //Modification to Orient the way they are viewing...
    //createPlayer(i, pX, pY,pZ,( (float)(((int)oY%360+180) *-1) )  );
    createMob(i, pX,pY,pZ,0);
    free(copy);

    Client_CheckCollision(pX,pY,pZ);
    i++; 
    playerToken = strtok_r(NULL,"|",&endToken_1);
  }


  //Clear the List of Players fron Wherever I left off


  BadMessage:
  for(;i<10;i++)
    hideMob(i);
  //Since the message is corrupt Leave the remaining players where they were last Correct
    return;
}

//Since collision is detected the same way, it's easy to kludge the results by letting the client handle calculations aswell
void Client_CheckCollision(int xpos, int ypos, int zpos)
{
            //Check if the projectile Collides with Anyblock (ANY block)
            if( world[xpos][ypos][zpos]!=0)
            {
               //Destroy the Projectile
               //DestroyProjectile(i);
               //Toggle Off Blocks in 

            //                x
            //               x x
            // 1*2       // xxxxx   
            // 1*1       //  x x    
            // 1*0       //   x    

         //Apply This in the Direction Up and Down     
            for(int depth=2; depth>-1;depth--)
               for(int squareX= xpos-(depth); squareX<= xpos+(depth); squareX++)
               for(int squareZ= zpos-(depth); squareZ<= zpos+(depth); squareZ++)
                  //Defensive Coding: Within Array Bounds
                  if( squareZ >=0 && squareZ<100 && squareX>=0 && squareX<100 && (ypos-depth)>=0 && (ypos-depth)<50)
                  {  
                     world[squareX][ (ypos- (2-depth))][squareZ]=0; 
                     world[squareX][ (ypos+ (2-depth))][squareZ]=0;                      
                  }   

            }
}


/*
 //For Legibility
            int xpos =(int)(projectile_Manager[i]->xPos);
            int ypos =(int)(projectile_Manager[i]->yPos);
            int zpos =(int)(projectile_Manager[i]->zPos);

            //Check if the projectile Collides with Anyblock (ANY block)
            if( world[xpos][ypos][zpos]!=0)
            {
               //Destroy the Projectile
               DestroyProjectile(i);
               //Toggle Off Blocks in 

            //                x
            //               x x
            // 1*2       // xxxxx   
            // 1*1       //  x x    
            // 1*0       //   x    

         //Apply This in the Direction Up and Down     
            for(int depth=2; depth>-1;depth--)
               for(int squareX= xpos-(depth); squareX<= xpos+(depth); squareX++)
               for(int squareZ= zpos-(depth); squareZ<= zpos+(depth); squareZ++)
                  //Defensive Coding: Within Array Bounds
                  if( squareZ >=0 && squareZ<100 && squareX>=0 && squareX<100 && (ypos-depth)>=0 && (ypos-depth)<50)
                  {  
                     world[squareX][ (ypos- (2-depth))][squareZ]=0; 
                     world[squareX][ (ypos+ (2-depth))][squareZ]=0;                      
                  }   

            }
*/








void Calculate_SpawnProjectile(float pX, float pY, float pZ, float oX,float oY,float oZ, double projVelocity, double projAngle)
{

         //All that is needed is to take our current XZ orientation
         //and determine the upward Y force which we will decay over time in ApplyGravity

         //Note Gravity plays no effect on X or Z force, instead wind would naturally have a
         //friction coefficient to reduce these values, but we will assume those are negligible

         //M_PI is pi defined in math.h
         //printf("Pi = %f\n", M_PI);
         long double radianAngle = (long double)projAngle * M_PI/180.0; 

      //Soh Cah Toa
         //Calculate Y and Horizontal Force
         double xzForce= (double)(cos(radianAngle)) * projVelocity;
         double yForce= (double)(sin(radianAngle)) * projVelocity;


        //Now to apply our xz force in the direction we are facing
         float orientationX= oX;
         float orientationY= oY;
         float orientationZ= oZ;

       //  getViewOrientation(&orientationX,&orientationY,&orientationZ);

         //X Controls Up/Down Pitch
         //Y Controls Yaw , which is whats needed for XZ force

         //Orientation produces weird results therefore constrain to 360%
         orientationY = (int) orientationY%360;

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

        double xForce= (double)(cos(radianAngle)) * xzForce;
        double zForce= (double)(sin(radianAngle)) * xzForce;

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

        SpawnProjectile(xForce,yForce,zForce, pX, pY,pZ);

        //char* message;
        //message= strdup("I want to Shoot a Projectile! :D\n");
        //send(client_SockFD, message, strlen(message), 0); 
}

