#include "clouds.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "clouds.h"
#include "graphics.h"

//---Global Values----
Cloud** skyClouds;


//The number of Clouds you'd like to populate the world
int num_Clouds=30;
int max_CloudSize=30;
//These Values are used to manipulate the direction wind is applied in, used for Cloud Movement
//Diagonal movements may cause jittering due to centroid + mod
float windForce_X=0;
float windForce_Z=0.1;
//=================  

void CreateSkyClouds()
   {
      skyClouds = malloc(num_Clouds * (sizeof(Cloud)));
      for(int i=0;i<num_Clouds;i++)
      {
         skyClouds[i]=CreateCloud();
      }
   }
   Cloud* CreateCloud()
   {
      Cloud* cloud = malloc(sizeof(Cloud));

      //Initialize Centroid Location

      //Randomize the Cloud Start Position
      cloud->pos_Y=50; //Set Heigh to Max Height

      cloud->pos_X= (int)(rand())% WORLDX;
      cloud->pos_Z= (int)(rand())% WORLDZ;  

      //Create Cloud Shape


      //How many voxels a cloud can be made up of at most
      cloud->cloudLength=max_CloudSize; 

      //Use CloudSize due to C complaining about int*.
      cloud->cloud_voxels = malloc( cloud->cloudLength * (sizeof(Cloud_Particle))); 
    //First Value must be Center
      cloud->cloud_voxels[0]= CreateParticle(0, 0, 0);

      int cloudCount=1;
      //Loop Through List 
      for(int i=1;i<cloud->cloudLength;i++)
      {
         int wasCloudAdded=0; //1= True
         //Increment through already made List to create neighbours in it
         for(int j=0;j<i;j++)
         {
            //For each Point in the list add a Neighbour
            int xPos= cloud->cloud_voxels[j].pos_X;
            int zPos= cloud->cloud_voxels[j].pos_Z;
            
            int xOffset;
            int zOffset;



            //Right
            xOffset=1+ xPos;
            zOffset=0+ zPos;
            //Random will be used to decide whether a vox is added or not
            if( (rand()%100) >50)
               if(isDuplicate(cloud, xOffset, zOffset)==0)
               {
                  cloudCount++;
                  cloud->cloud_voxels[i]= CreateParticle(xOffset,0,zOffset);
                  wasCloudAdded=1;
                  break;
               }

            //Left
            xOffset=-1+ xPos;
            zOffset=0+ zPos;
            if( (rand()%100) >50)
               if(isDuplicate(cloud, xOffset, zOffset)==0)
               {
                  cloudCount++;
                  cloud->cloud_voxels[i]= CreateParticle(xOffset,0,zOffset);
                  wasCloudAdded=1;
                  break;
               }
            //Forward
            xOffset=0+ xPos;
            zOffset=1+ zPos;
            if( (rand()%100) >50)
               if(isDuplicate(cloud, xOffset, zOffset)==0)
               {
                  cloudCount++;
                  cloud->cloud_voxels[i]= CreateParticle(xOffset,0,zOffset);
                  wasCloudAdded=1;
                  break;
               }
            //Backward
            xOffset=0+ xPos;
            zOffset=-1+ zPos;
            if( (rand()%100) >50)            
               if(isDuplicate(cloud, xOffset, zOffset)==0)
               {
                  cloudCount++;
                  cloud->cloud_voxels[i]= CreateParticle(xOffset,0,zOffset);
                  wasCloudAdded=1;
                  break;
               }


         }
         //Cloud was not added, realign I
         if(wasCloudAdded==0)
            i--;
      }
      return cloud;
   }


   //0=False, 1 = True
   //Checks if a cloudVoxel exists at the offset location provided
   int isDuplicate(Cloud cloud, int xOffset, int zOffset)
   {
      for(int i=0;i<cloud.cloudLength;i++)
      {
         if(cloud.cloud_voxels[i].pos_X == xOffset && cloud.cloud_voxels[i].pos_Z == zOffset)   
         {
         return 1;
         }
      }
     return 0;
   }


   //Creates a Cloud Particle
   Cloud_Particle CreateParticle(int x, int y, int z)
   {
      Cloud_Particle cP;// = malloc(sizeof(Cloud_Particle));
      //cP.pos_X = malloc(sizeof(int));
      //cP.pos_Y = malloc(sizeof(int));
      //cP.pos_Z = malloc(sizeof(int));

      cP.pos_X=x;
      cP.pos_Y=y;
      cP.pos_Z=z;

      return cP;     
   }


   //Animates the Clouds
   void UpdateCloudMovement()
   {
      //Clear the Sky of clouds
      for(int x=0;x<WORLDX;x++)
         for(int z=0;z<WORLDZ;z++)
            if(world[x][WORLDY-1][z]==5)
               world[x][WORLDY-1][z]=0;

      //Draw Clouds   
      //Increment Cloud Position
      for(int i=0;i<num_Clouds;i++)
      {
         skyClouds[i]->pos_X += windForce_X;
         skyClouds[i]->pos_Z += windForce_Z;

      //The Actual cloud position does not matter due to all values being modded.
      //Modding the offsets off the centroid equates to clouds which wrap around the sky
      //this is a very cool effect which is why I'm doing it this way.

         //if skyClouds[i] >200 (twice the size of the box, then reset to 0)
         if(skyClouds[i]->pos_X> WORLDX*2)
            skyClouds[i]->pos_X=0;
          if(skyClouds[i]->pos_Z> WORLDZ*2)
            skyClouds[i]->pos_Z=0;        

         //For Each Cloud Create White Cubes at correct Location
         //printf("Cloud[%d]: Length:%d", i, skyClouds[i]->cloudLength);
         for(int j=0;j<skyClouds[i]->cloudLength;j++)
         {
            //Find Location
            int cloudCube_X = (int)skyClouds[i]->pos_X;
            int cloudCube_Z = (int)skyClouds[i]->pos_Z;

            //Apply offset
            cloudCube_X+= skyClouds[i]->cloud_voxels[j].pos_X;
            cloudCube_Z+= skyClouds[i]->cloud_voxels[j].pos_Z;


            //Mod for World Wrap
            if(cloudCube_X>=0)
               cloudCube_X= cloudCube_X% WORLDX;     
            //This has to be done due to -Numbers not modding Correctly
            else      
               {
                  cloudCube_X = WORLDX-((-1*cloudCube_X) % WORLDX);
               }

            if(cloudCube_Z>=0)
               cloudCube_Z= cloudCube_Z% WORLDZ;     
            //This has to be done due to -Numbers not modding Correctly
            else      
               {
                  cloudCube_Z = WORLDZ-((-1*cloudCube_Z) % WORLDZ);
               }

            //If the Cell is Empty
            if( world[cloudCube_X][WORLDY-1][cloudCube_Z]==0)
               world[cloudCube_X][WORLDY-1][cloudCube_Z]=5;
         }
      }

   }


   //Free Malloced Memory
   void DestroySkyClouds()
   {
      for(int i=0;i<num_Clouds;i++)
      {
      //   printf("Destroying a Cloud! [%d]\n",i);
         DestroyCloud(skyClouds[i]);
      }
      free(skyClouds);
      //printf("Free this:Skycloud\n");
   }

   //Free Malloced Memory
   void DestroyCloud(Cloud* cloud)
   {
      //printf("Free: Cloud XYZ\n");
      //free(cloud.pos_X);
      //free(cloud.pos_Y);
      //free(cloud.pos_Z);
      //printf("Free:cloud_Voxels\n");
      for(int i=0;i<cloud->cloudLength;i++)
      {
         //printf("Free: Cloud Vox[%d]/%d XYZ\n",i,cloud->cloudLength);
          //free(cloud.cloud_voxels[i].pos_X);
          //free(cloud.cloud_voxels[i].pos_Y);
          //free(cloud.cloud_voxels[i].pos_Z);        
      }
      free(cloud->cloud_voxels);
      free(cloud);
      //printf("Free this:Cloud\n");
   }
