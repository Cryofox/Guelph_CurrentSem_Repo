#ifndef PROJECTILE
#define PROJECTILE
   //This is a struct for Managing Projectile Information
   struct 
   {
      int id;
      float xForce;
      float yForce;
      float zForce;

      float xPos;
      float yPos;
      float zPos;



      //This value is used for Decaying the Projectiles YForce
      //Downward force of Gravity = Gravity * ProjectileMass -
      //yForce does not become negative.

      float mass;
      float acceleration_Downward;
      /* data */
   }typedef projectile;

   void DestroyProjectileManager();
   void CreateProjectileManager();
   void SpawnProjectile( float xForce, float yForce, float zForce, float xPos,float yPos,float zPos);
   void UpdateProjectiles(double timePassed);
   void DestroyProjectile(int index);

//Code Called by Server to Send Player List to Players
char* Stringify_Projectiles();

void Calculate_SpawnProjectile(float pX, float pY, float pZ, float oX,float oY,float oZ, double projVelocity, double projAngle);

   
#endif