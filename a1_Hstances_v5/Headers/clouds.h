#ifndef CLOUDS
#define CLOUDS

   //This is 1 "Voxel"/Cube that Makes up the Cloud
   typedef struct{
      int pos_X;
      int pos_Y;
      int pos_Z;
   }Cloud_Particle;

   typedef struct{
   //This is the Centroid position of the Cloud.
   //All of the Cloud Particles will be Offset based on this
   //center position
      float pos_X;
      float pos_Y;
      float pos_Z; 
   //List of Cloud_Particles     
      Cloud_Particle* cloud_voxels;
   //Particle Length of Array
      int cloudLength;
   }Cloud;

   //Creates a Cloude Particle/Voxel, the term is interchanged as they are both atomic
   Cloud_Particle CreateParticle(int x, int y, int z);
   //This Function Populates the global SkyCloud Pointer
   void CreateSkyClouds();

   //This Function Destroys all SkyCloud children and the Skycloud itself
   //IE ALL cloudS
   void DestroySkyClouds();

   //This Creates a Single Cloud
   Cloud* CreateCloud();

   //This Destroys a Single Cloud
   void DestroyCloud(Cloud* cloud);

   int isDuplicate(Cloud* cloud, int xOffset, int zOffset);

   void UpdateCloudMovement();
#endif