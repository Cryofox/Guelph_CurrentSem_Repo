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




   //This creates a Manager which Manages all spawned Projectiles, the only
   //code that is relevant is CreateManager, and Free, as Apply Gravity, will call
   //on ALL projectiles within ProjectileManager
   projectile** projectile_Manager;
   int projectile_Count=0;
   int max_Projectiles= MOB_COUNT; // Since projectiles are dependent upon Mobs, that is the projectile Max

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
   void SpawnProjectile( float xForce, float yForce, float zForce)
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

      float currLoc_X;
      float currLoc_Y;
      float currLoc_Z;

      getViewPosition(&currLoc_X, &currLoc_Y, &currLoc_Z);

      int mass=5;
      //Create the Projectile
      projectile* newProjectile = malloc(sizeof(projectile));

      newProjectile->id = id;
      newProjectile->xForce= xForce;
      newProjectile->yForce= yForce;
      newProjectile->zForce= zForce;

      newProjectile->xPos= currLoc_X*-1;
      newProjectile->yPos= currLoc_Y*-1;
      newProjectile->zPos= currLoc_Z*-1;

      //Need to set it directly infront of the view
      newProjectile->mass =mass;
      //Force = Mass * Acceleration, therefore Force/Mass = Acceleration
      newProjectile->acceleration_Downward = -(mass/yForce); //Zero Gravity Acting at this point

      projectile_Manager[projectile_Count]= newProjectile;
      projectile_Count++;

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
      float gravity = gravity_Force;

      //For Each Particle Check if it has intersected with a bloc
      for(int i=0;i< projectile_Count;i++)    
      {
         //Collision Detect: Bounds, XZ and Ground. The roof is not Counted as a Bound so projectiles can leave and enter the zone
         //if angled correctly.
         if(((projectile_Manager[i]->xPos) > 100 || (projectile_Manager[i]->xPos) <0) || ((projectile_Manager[i]->zPos) > 100 || (projectile_Manager[i]->zPos) <0) || (projectile_Manager[i]->yPos<0)) 
            DestroyProjectile(i);
         else
         {
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

