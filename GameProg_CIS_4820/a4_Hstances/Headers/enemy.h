#ifndef PROJECTILE
#define PROJECTILE
   //This is a struct for Managing Projectile Information
   struct 
   {

      float xPos;
      float yPos;
      float zPos;


      //This is used for the direction we wish to go in aswell
      float faceRotation;

      int pointX;
      int pointZ;


      float time_LastSpotted; //How long since the Player was viewed
      float time_LastShot;
      float time_LastDodge;
      int id;
   }typedef enemy;


   void CreateEnemyManager();
   void DestroyEnemyManager();
   void SpawnEnemy(float xpos, float ypox, float zpos);
   void DestroyEnemy(int index);

  void Mob_Player_Hit(float x, float y,float z);

   void UpdateEnemies(double timePassed);









#endif