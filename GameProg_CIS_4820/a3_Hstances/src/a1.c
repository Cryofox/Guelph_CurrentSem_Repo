
/* Derived from scene.c in the The OpenGL Programming Guide */
/* Keyboard and mouse rotation taken from Swiftless Tutorials #23 Part 2 */
/* http://www.swiftless.com/tutorials/opengl/camera2.html */

/* Frames per second code taken from : */
/* http://www.lighthouse3d.com/opengl/glut/index.php?fps */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "clouds.h"
#include "graphics.h"
#include "perlin.h"
#include "projectile.h"
#include <sys/time.h>  //Used for Timing Functions


#include <stdio.h>
#include <string.h>   //strlen
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>   //close
#include <arpa/inet.h>    //close
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/time.h> //FD_SET, FD_ISSET, FD_ZERO macros


	/* flag which is set to 1 when flying behaviour is desired */
extern int flycontrol;
	/* flag used to indicate that the test world should be used */
extern int testWorld;




//External Reference to Client/Server flags
extern int netClient;      // network client flag, is client when = 1
extern int netServer;      // network server flag, is server when = 1

#define PORT 8888
#define TRUE   1
#define FALSE  0


    int opt = TRUE;
    int master_socket , addrlen , new_socket , client_socket[30] , max_clients = 30 , activity, i , valread , sd;
    int max_sd;
    struct sockaddr_in address;
      
    int client_SockFD;
    char buffer[1025];  //data buffer of 1K
      
    //set of socket descriptors
    fd_set readfds;
      



    struct timeval time_SelectTimeout;


typedef struct{
  float px,py,pz,ox,oy,oz;
  double angle,velocity;
  int shootFlag, id;
}PlayerInfo;

PlayerInfo** PlayerList;
int plSize=0;
//Destruction LIST
//

void CreatePlayerManager()
{
  if(PlayerList==NULL)
     PlayerList =malloc( 10 * sizeof(PlayerInfo));  
}

//When a Player Connects we Store the SocketD into a player struct as ID
void AddPlayer(int sd)
{
  PlayerInfo* player = malloc( sizeof(PlayerInfo));
  player->id = sd;
  player->px     =0; 
  player->py     =0;
  player->pz     =0; 
  player->ox     =0; 
  player->oy     =0; 
  player->oz     =0; 
  player->angle  =0;
  plSize++;
}
//When a Player Disconnects or Dies, remove the Player from List
void DeletePlayer(int id)
{
  int index=-1;
  for(int i=0;i<plSize;i++)
    if(PlayerList[i]->id ==id)
    {  index=i;
      break;}

  if(index==-1)
    return;
//Remove at Index and shift towards the left
      for(int i=index;i< plSize;i++)
      {
         free(PlayerList[i]);
         PlayerList[i]=malloc(sizeof(PlayerInfo));

         //Duplicate Struct Contents
         if(i+1 < plSize)
            *PlayerList[i] = *PlayerList[(i+1)];
      }
      plSize--;
}


void UpdatePlayers(PlayerInfo* player)
{
  //We have a Struct containing player info, assign values to match on SD
  for(int i=0;i<plSize;i++)
  {
    if(PlayerList[i]->id == player->id)
    {
      //Only store needed Data, velocity shootflag not needed for play pos/orientation
      PlayerList[i]->px     =player->px; 
      PlayerList[i]->py     =player->py;
      PlayerList[i]->pz     =player->pz; 
      PlayerList[i]->ox     =player->ox; 
      PlayerList[i]->oy     =player->oy; 
      PlayerList[i]->oz     =player->oz; 
      PlayerList[i]->angle  =player->angle;
    }
  }
}

//Code Called by Server to Send Player List to Players
char* Stringify_Players()
{
  printf("SO YAH WANT TO STRINGIFY\n");
  char* string;
  char message[1000];

  char portion[100] ;
  //All that is needed
    for(int i=0;i<plSize;i++)
    {
      /*     //X Loc
           snprintf(portion,100,"%f",PlayerList[i]->px);
           strcat(message,portion);
           strcat(message,",");

           //Y Loc
           snprintf(portion,100,"%f",PlayerList[i]->py);
           strcat(message,portion);
           strcat(message,",");

           //Z Loc
           snprintf(portion,100,"%f",PlayerList[i]->pz);
           strcat(message,portion);
           strcat(message,",");

           //X Orient
           snprintf(portion,100,"%f",PlayerList[i]->ox);
           strcat(message,portion);
           strcat(message,",");

           //Y Orient
           snprintf(portion,100,"%f",PlayerList[i]->oy);
           strcat(message,portion);
           strcat(message,",");

           //Angle
           snprintf(portion,100,"%f",PlayerList[i]->angle);
           strcat(message,portion);
           strcat(message,"|");//Char used to seperate players*/
    }
    strcat(message,"\0");
    string=strdup(message);
    printf("Works tillher :D\n");
    return string;
}





//Creates a Struct Representation of the String Passed by the Client to the Server
PlayerInfo* ParsePlayer_Info(char* string, int id)
{
  PlayerInfo* player = malloc( sizeof(PlayerInfo));

    char* token = strtok(string, ",");
    if(token==NULL)
      goto BadMessage;
    //printf("token: %s\n", token);
    player->px = atof(token);
    printf("Token=%s\n",token);



    token = strtok(NULL,",");
    if(token==NULL)
      goto BadMessage;
    player->py = atof(token);
    printf("Token=%s\n",token);


    token = strtok(NULL,",");
    if(token==NULL)
      goto BadMessage;
    player->pz = atof(token);
    printf("Token=%s\n",token);


    token = strtok(NULL,",");
    if(token==NULL)
      goto BadMessage;
    player->ox = atof(token);
    printf("Token=%s\n",token);


    token = strtok(NULL,",");
    if(token==NULL)
      goto BadMessage;
    player->oy = atof(token);
    printf("Token=%s\n",token);


    token = strtok(NULL,",");
    if(token==NULL)
      goto BadMessage;
    player->oz = atof(token);
    printf("Token=%s\n",token);


    token = strtok(NULL,",");
    if(token==NULL)
      goto BadMessage;
    player->angle = atof(token);
    printf("Token=%s\n",token);


    token = strtok(NULL,",");
    if(token==NULL)
      goto BadMessage;
    player->velocity = atof(token);
    printf("Token=%s\n",token);



    token = strtok(NULL,",");
    if(token==NULL)
     goto BadMessage;

    player->shootFlag = atoi(token);
    printf("Token=%s\n",token);

    player->id=id;
   // free(token);
  return player;

BadMessage:
    free(player);
    return NULL;


}

//Moved here so Can be called from Update
float xForce;
float yForce;
float zForce;
int shootFlag= FALSE ;


//The Projectiles Angle to be Used from the Forward view
static double projectile_Angle=0.0;
static double projectile_Velocity=100;



   //Functions used, these need to be appended to H

   //Applies Gravity
   void ApplyGravity(double timePassed);
   //Call Destroy on created ptrs (atm it's just skyclouds)
   void ExitCleanUpCode();

   //Updates the Elapsed time from the last time this was Called.
   //This is called every time Update is called from opengl
   double UpdateTime();



   //Structs from Time.h used for Calculating Elapsed Time
   struct timeval time_LastUpdate, time_thisUpdate;




   float gravity_Force = 2;

/*
                     //You want to Send 49 Sets of Planes to generate the World
             
             char myBuffer[ (WORLDX*WORLDZ)];
             // myBuffer[0]='H';
             //printf("BufferLen=%d\n", (int)(sizeof(myBuffer)));

             char c='N';
             printf("CharC=%c\n",c);
             for(int x=0;x< WORLDX;x++)
             {
              int i = 1 + (int)'0';
              c= (char)i;
              printf("INT=%d\n",c);
              printf("Buffer[I]=%c<\n",c);
             }
*/

int digit_to_int(char d)
{
  char temp[2];
  temp[0]=d;
  temp[1]='\0';
  return (int) strtol(temp,NULL,10);

}


char* Stringify_Plane(int yVal)
{
   char* str_World;

   //printf("YVALU=====================================================\n");
   char strBuffer[ (WORLDX)*(WORLDZ) +1];
   memset(strBuffer,0, ((WORLDX)*(WORLDZ)));
   int i=0;
   for(int x=0; x< WORLDX;x++)
         for(int z=0; z< WORLDZ ;z++)
            {
               //Grab Character Equiv of I ie  int 5 = char '5'


               int val = (world[x][yVal][z]) + (int)'0';

               //This code is added because casting Char is not
               //working, for some weird reason, I spent 2 hours on a trivial
               //cast and yet it wont work. char c= (char) val; Should = the single numeric digit, yet it does not.
               strBuffer[i]= (char)val;
               //strBuffer[i]='5';
              // printf("C=%d_\n",c);
              // printf("I=%d_\n",(world[x][yVal][z]));

      //         printf("The Integer=%d\n",val);
     //          printf("The Charact=%c\n",strBuffer[i]);
      //         printf("I=%d\n",i);
               i++;
            }  
    strBuffer[i]='\0';

   str_World= strdup(strBuffer);
   printf("Buffer=%s\n",strBuffer);
       printf("I=%d\n",i);
   //printf("STR_WORLD=%s\n",str_World);    
   //free(str_World); 
   return str_World;
}

void DeString_Plane(char* msg, int height)
{
   printf("Msg=%s\n",msg);
   int i=0;
   for(int x=0; x< WORLDX;x++)
      for(int z=0; z< (WORLDZ);z++)
         {
            int val= digit_to_int(msg[i]);
            world[x][height][z]= val;
          //  printf("I=%d\n",world[x][height][z]);
            i++;
         }  

}



//Server is handled in backwards Logic Fashion
//Clients Say what they do, and server just sends to everyone
void Initialize_Server()
{
   //The Network Logic

   //Wait 0.1second For Socket Reading to interupt physics steps
   time_SelectTimeout.tv_sec =  1;
   time_SelectTimeout.tv_usec = 0;

   //Upon First Connection, Client need to Create the World and
   //Players and Projectiles
//initialise all client_socket[] to 0 so not checked
    for (i = 0; i < max_clients; i++) 
    {
        client_socket[i] = 0;
    }
      
    //create a master socket
    if( (master_socket = socket(AF_INET , SOCK_STREAM , 0)) == 0) 
    {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
  
    //set master socket to allow multiple connections , this is just a good habit, it will work without this
    if( setsockopt(master_socket, SOL_SOCKET, SO_REUSEADDR, (char *)&opt, sizeof(opt)) < 0 )
    {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
  
    //type of socket created
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons( PORT );
      
    //bind the socket to localhost port 8888
    if (bind(master_socket, (struct sockaddr *)&address, sizeof(address))<0) 
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    printf("Listener on port %d \n", PORT);
     
    //try to specify maximum of 3 pending connections for the master socket
    if (listen(master_socket, 3) < 0)
    {
        perror("listen");
        exit(EXIT_FAILURE);
    }
      
    //accept the incoming connection
    addrlen = sizeof(address);
    puts("Waiting for connections ...");

}



void Initialize_Client()
{
   int result;
   int len;
   /*  Create a socket for the client.  */
    client_SockFD = socket(AF_INET, SOCK_STREAM, 0);

   /*  Name the socket, as agreed with the server.  */
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = inet_addr("127.0.0.1");
    address.sin_port = htons(PORT);
    len = sizeof(address);

   /*  Now connect our socket to the server's socket.  */
    result = connect(client_SockFD, (struct sockaddr *)&address, len);

    if(result == -1) {
        perror("oops: client3");
        exit(1);
    }
    char msg[ (WORLDX*WORLDZ)];
    int buffer= 512;

 //   char * msg = malloc( sizeof(char) * (WORLDX*WORLDY*WORLDZ));
    int msgSize= sizeof(char) * (WORLDX*WORLDZ);



   //GenerateWorld Copy
    for(int i=0;i<49;i++)
    {
      printf("Count=%d\n",i);
      printf("MessageLength Pre: %d\n", (int)(strlen(msg)));
      memset(msg,0, msgSize);
      recv(client_SockFD, msg, msgSize, 0);
      printf("recv\n");
      char* str_Plane = strdup(msg);
      printf("strdup\n");

      DeString_Plane(str_Plane, i);
      free(str_Plane);
    }
    //Genereate Cloud Motion
    float timePassedGlobal;
    recv(client_SockFD, &timePassedGlobal, sizeof(timePassedGlobal), 0);

     //Lets Create some Clouds
     CreateSkyClouds();
     UpdateCloudMovement(timePassedGlobal);

    //printf("Server Message:%s", msg);
    printf("MessageLength Post: %d\n", (int)(strlen(msg)));




    //The Client will Recieve a Message
}




	/*** collisionResponse() ***/
	/* -performs collision detection and response */
	/*  sets new xyz  to position of the viewpoint after collision */
	/* -can also be used to implement gravity by updating y position of vp*/
	/* note that the world coordinates returned from getViewPosition()
	   will be the negative value of the array indices */

//This function only gets called on Keyboard Press, not exactly Ideal for Gravity
//Setting a Flag here to determine what's calling it can provide an easy fix as to the Hopping Glitch
void collisionResponse() 
{
	/* your collision code goes here */
   float currLoc_X;
   float currLoc_Y;
   float currLoc_Z;

   getViewPosition(&currLoc_X, &currLoc_Y, &currLoc_Z);

   currLoc_X*=-1;
   currLoc_Y*=-1;
   currLoc_Z*=-1;
   currLoc_Y-=.5; //This value is used for Head-Repositioning

   //Apply Bound Checking
   if(( currLoc_X > 100 || currLoc_X < 0) || ( currLoc_Z > 100 || currLoc_Z < 0))
   {
      float oldLoc_X;
      float oldLoc_Y;
      float oldLoc_Z;     

      //There will be a Y difference due to gravity constantly trying to push
      //us through the ground (just like in life :D)

      getOldViewPosition(&oldLoc_X, &oldLoc_Y, &oldLoc_Z);     
      setViewPosition((oldLoc_X), (oldLoc_Y), (oldLoc_Z));
   }


   //Otherwise if we are entering a non Empty && non blue then don't go into it!
   else if(world[(int)currLoc_X][(int)currLoc_Y][(int)currLoc_Z]!=0 && world[(int)currLoc_X][(int)currLoc_Y][(int)currLoc_Z]!=5)
   {
      //Silly Statement the computer says. Wouldn't you scream if you walked through walls?
      //printf("IM ENTERING A BLOCK AHAHHHHHHH=\n");

      //Reuse xyz variables, as condition has been checked
      //This is useless if keyboard was not pressed
      float oldLoc_X;
      float oldLoc_Y;
      float oldLoc_Z;     

      //There will be a Y difference due to gravity constantly trying to push
      //us through the ground (just like in life :D)

      getOldViewPosition(&oldLoc_X, &oldLoc_Y, &oldLoc_Z);

      oldLoc_X*=-1;
      oldLoc_Y*=-1;
      oldLoc_Z*=-1;

      oldLoc_Y=  ((int)oldLoc_Y)+.5;

      //Only do this if we are not moving
      //Check if a block exists here, but not at the elevation above

      //Only Perform this "HOP" mechanic if the following criteria is met:
      //1. A difference occured in the X and/or Z
      //2. We are not attempting to move down, otherwise a jostle will occur due to gravity + hop
      //3. There is a block at the location we are attempting to move onto, AND nothing ontop.
      //4. This move is not called by Gravity, this is important because gravity will always force down
         if(world[(int)currLoc_X][ (int)(oldLoc_Y)][(int)currLoc_Z]!=0) 
         {      
            if(world[(int)currLoc_X][ (int)(oldLoc_Y+1)][(int)currLoc_Z]==0)
            {
            oldLoc_X=currLoc_X;
            oldLoc_Z=currLoc_Z; 
            oldLoc_Y+=1;
            }
         }
         else
         {
          oldLoc_X=currLoc_X;
          oldLoc_Z=currLoc_Z;  
         }

      setViewPosition((oldLoc_X*-1), (oldLoc_Y*-1), (oldLoc_Z*-1));
   }
}

   /******* draw2D() *******/
   /* draws 2D shapes on screen */
   /* use the following functions:        */
   /* draw2Dline(int, int, int, int, int);      */
   /* draw2Dbox(int, int, int, int);         */
   /* draw2Dtriangle(int, int, int, int, int, int);   */
   /* set2Dcolour(float []);           */
   /* colour must be set before other functions are called  */
void draw2D() {

   if (testWorld) {
      /* draw some sample 2d shapes */
      GLfloat green[] = {0.0, 0.5, 0.0, 0.5};
      set2Dcolour(green);
      draw2Dline(0, 0, 500, 500, 15);
      draw2Dtriangle(0, 0, 200, 200, 0, 200);

      GLfloat black[] = {0.0, 0.0, 0.0, 0.5};
      set2Dcolour(black);
      draw2Dbox(500, 380, 524, 388);
   } else {

   /* your code goes here */

   }

}
float time_Passed_ServerStart=0;

	/*** update() ***/
	/* background process, it is called when there are no other events */
	/* -used to control animations and perform calculations while the  */
	/*  system is running */
	/* -gravity must also implemented here, duplicate collisionResponse */
void update() {
int i, j, k;
float *la;
	/* sample animation for the test world, don't remove this code */
	/* -demo of animating mobs */
   if (testWorld) {
	/* sample of rotation and positioning of mob */
	/* coordinates for mob 0 */
      static float mob0x = 50.0, mob0y = 25.0, mob0z = 52.0;
      static float mob0ry = 0.0;
      static int increasingmob0 = 1;
	/* coordinates for mob 1 */
      static float mob1x = 50.0, mob1y = 25.0, mob1z = 52.0;
      static float mob1ry = 0.0;
      static int increasingmob1 = 1;

	/* move mob 0 and rotate */
	/* set mob 0 position */
      setMobPosition(0, mob0x, mob0y, mob0z, mob0ry);

	/* move mob 0 in the x axis */
      if (increasingmob0 == 1)
         mob0x += 0.2;
      else 
         mob0x -= 0.2;
      if (mob0x > 50) increasingmob0 = 0;
      if (mob0x < 30) increasingmob0 = 1;

	/* rotate mob 0 around the y axis */
      mob0ry += 1.0;
      if (mob0ry > 360.0) mob0ry -= 360.0;

	/* move mob 1 and rotate */
      setMobPosition(1, mob1x, mob1y, mob1z, mob1ry);

	/* move mob 1 in the z axis */
	/* when mob is moving away it is visible, when moving back it */
	/* is hidden */
      if (increasingmob1 == 1) {
         mob1z += 0.2;
         showMob(1);
      } else {
         mob1z -= 0.2;
         hideMob(1);
      }
      if (mob1z > 72) increasingmob1 = 0;
      if (mob1z < 52) increasingmob1 = 1;

	/* rotate mob 1 around the y axis */
      mob1ry += 1.0;
      if (mob1ry > 360.0) mob1ry -= 360.0;
    /* end testworld animation */
   } else {


      if(netServer==1)
      {
            /* your code goes here */
         double timePassed=UpdateTime();
         time_Passed_ServerStart+=timePassed;
         
         //Gravity Code
         if(flycontrol==0)
            ApplyGravity(timePassed);
         //Look in clouds.c
         UpdateCloudMovement(timePassed);

         UpdateProjectiles(timePassed);

         //printf("Calculated Physics Step:\n");
        




        // printf("Server Logics...\n");

         FD_ZERO(&readfds);
         //add master socket to set
         FD_SET(master_socket, &readfds);
         max_sd = master_socket;

        //add child sockets to set
         for ( i = 0 ; i < max_clients ; i++) 
         {
            //socket descriptor
            sd = client_socket[i];
             
            //if valid socket descriptor then add to read list
            if(sd > 0)
               FD_SET( sd , &readfds);
             
            //highest file descriptor number, need it for the select function
            if(sd > max_sd)
               max_sd = sd;
         }
        //wait for an activity on one of the sockets 
        activity = select( max_sd + 1 , &readfds , NULL , NULL , &time_SelectTimeout);
    
        if ((activity < 0) && (errno!=EINTR)) 
        {
            printf("select error\n");
        }

         //If something happened on the master socket , then its an incoming connection
        if (FD_ISSET(master_socket, &readfds)) 
        {
            if ((new_socket = accept(master_socket, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0)
            {
                perror("accept");
                exit(EXIT_FAILURE);
            }
          

            //Send Current World Data


            //Send Plane Information to the Player Untill a World is Created

            //Send the Current State of the World
            for(int y=0;y<49;y++)
            {
              printf("Y=%d\n",y);
              char* stringPlane=Stringify_Plane(y);
              send(new_socket, stringPlane, strlen(stringPlane), 0);
              free(stringPlane);
            }

            //Send the Current Time passed for Current Cloud Position
             send(new_socket, &time_Passed_ServerStart, sizeof(time_Passed_ServerStart), 0);





            puts("Welcome Configurations sent successfully");
              
            //add new socket to array of sockets
            for (i = 0; i < max_clients; i++) 
            {
                //if position is empty
                if( client_socket[i] == 0 )
                {
                    client_socket[i] = new_socket;
                    printf("Adding to list of sockets as %d\n" , i);
                    AddPlayer(client_socket[i]);
                    //return;
                }
            }
        }
        //else its some IO operation on some other socket :)
        for (i = 0; i < max_clients; i++) 
        {
            sd = client_socket[i];
              
            if (FD_ISSET( sd , &readfds)) 
            {
                //Check if it was for closing , and also read the incoming message
                if ((valread = read( sd , buffer, 1024)) == 0)
                {
                    //Somebody disconnected , get his details and print
                    getpeername(sd , (struct sockaddr*)&address , (socklen_t*)&addrlen);
                    printf("Host disconnected , ip %s , port %d \n" , inet_ntoa(address.sin_addr) , ntohs(address.sin_port));
                      
                    //Close the socket and mark as 0 in list for reuse
                    close( sd );
                    client_socket[i] = 0;
                }
                  
                //Echo back the message that came in
                else
                {
                //Print the Message Sent from Socket
                  printf("W!\n");
                  printf("Message From Client: %s\n",buffer);
                  printf("M!\n");
                  
                  // Player Sends 1 Message

                  //Clients Send Their Position orientation, angle,velocity, and whether or not they wish to spawn a projectile

                  // PosX,PosY,posZ,OrientX,OrientY,OrientZ,Angle,Vel,T/F

                  //We have to Parse the Information now
                  char* strCopy = strdup(buffer);

                  printf("ID=%d\n",sd );
                  PlayerInfo* player = ParsePlayer_Info(strCopy, sd);

                  //If The Message was bad we don't need to free

                  //Now we have a Player with all the Information required to position, orient, and Shoot projectiles.

                  
                  //Whenever a Player Sends info, we update the PlayerList


                  // Server Sends 2 List of Players
                  //                List of Projectiles

  


                  //char* playerListMessage;
                  //playerListMessage=Stringify_Players();

                  //Sending the First Message of Players to Draw
                  //send(sd, playerListMessage, sizeof(playerListMessage), 0);
    


                  //free(playerListMessage);
                  free(strCopy);

                  if(player!=NULL)
                    //UpdatePlayers(player);
                    free(player);
                  //Update the Players Position
                  



                    //set the string terminating NULL byte on the end of the data read
                  //  buffer[valread] = '\0';
                //    send(sd , buffer , strlen(buffer) , 0 );
                }
            }
        }

      }

      else if(netClient==1)
      {
        //Update CloudMovement, They're already synced so its fine to do it here now.
            /* your code goes here */
         double timePassed=UpdateTime();
         time_Passed_ServerStart+=timePassed;
         
         //Gravity Code
         if(flycontrol==0)
            ApplyGravity(timePassed);
         //Look in clouds.c
         UpdateCloudMovement(timePassed);


         //First We Update out Messages with the Server, Then we Send our Message


         //If Our New Position is Different than our old one, tell the Server that.

         //Send the Server our info
         // PosX,PosY,posZ,OrientX,OrientY,OrientZ,Angle,Vel,T/F

         //Now we can Pass the Info

          /* your collision code goes here */
           float currLoc_X;
           float currLoc_Y;
           float currLoc_Z;

           getViewPosition(&currLoc_X, &currLoc_Y, &currLoc_Z);

           currLoc_X*=-1;
           currLoc_Y*=-1;
           currLoc_Z*=-1;
           currLoc_Y-=.5; //This value is used for Head-Repositioning

           //Now for our Orientation

           float orientationX;
           float orientationY;
           float orientationZ;

           getViewOrientation(&orientationX,&orientationY,&orientationZ);
           //Now to Create our string


           char message[1000];

           char portion[100];


           memset(message,0,500);
           //X Loc
           snprintf(portion,100,"%f",currLoc_X);
           strcat(message,portion);
           strcat(message,",");

           //Y Loc
           snprintf(portion,100,"%f",currLoc_Y);
           strcat(message,portion);
           strcat(message,",");

           //Z Loc
           snprintf(portion,100,"%f",currLoc_Z);
           strcat(message,portion); 
           strcat(message,",");

           //X Orient
           snprintf(portion,100,"%f",orientationX);
           strcat(message,portion);
           strcat(message,",");

           //Y Orient
           snprintf(portion,100,"%f",orientationY);
           strcat(message,portion);
           strcat(message,",");

           //Z Orient
           snprintf(portion,100,"%f",orientationZ);
           strcat(message,portion);
           strcat(message,",");


           //Angle
           snprintf(portion,100,"%f",projectile_Angle);
           strcat(message,portion);
           strcat(message,",");

           //Velocity
           snprintf(portion,100,"%f",projectile_Velocity);
           strcat(message,portion);
           strcat(message,",");

           if(shootFlag==TRUE)
            strcat(message,"T");
           else
            strcat(message,"F");


          strcat(message,"\0");

          //Now we can send our Message
          send(client_SockFD, message, sizeof(message), 0);

          //Once message is set, reset our flag
          shootFlag=FALSE;


         //Server is ALWAYS Sending Messages, Check if we RECV them.

         //Message 1= Player Positions and Orientations
         //Message 2= Projectile Positions
         // recv(client_SockFD, message, sizeof(message), 0);
          //printf("Message from Server:%s\n",message);


      }
   }

}
   int firstTime=0;
   //This Function Updates the Time and Returns the elapsed time since the last time it was called
   //Updates the Elapsed time from the last time this was Called.
   //This is called every time Update is called from opengl
   double UpdateTime()
   {
      //This is the first time Calc Elapsed time has been called. Meaning
      //Start the procedure correctly
      if(firstTime==0)
      {
      firstTime=1;
      gettimeofday(&time_thisUpdate, NULL);
      return 0;
      }
      else
      {
      //Store the old_current time
      time_LastUpdate=time_thisUpdate;
      //Calculate the actual current time
      gettimeofday(&time_thisUpdate, NULL);  

      //Calculate the Elapsed time between timeStamps
      double elapsedTime;

      //Calculate in two steps to preserve accuracy
      elapsedTime =  (time_thisUpdate.tv_sec  - time_LastUpdate.tv_sec) * 1000.0;    // sec to ms
      elapsedTime += (time_thisUpdate.tv_usec - time_LastUpdate.tv_usec) / 1000.0;   // us to ms

      //Convert Millisecond back to Seconds
      elapsedTime /= 1000.0;
      //printf("Elapsed Time:%f\n",elapsedTime);
      return elapsedTime;
      }
   }

   


   //This function will decrement the value by .1 if a block is not directly underneath
   void ApplyGravity(double timePassed)
   {
      float gravity = gravity_Force;
      gravity*= timePassed;

      float currLoc_X;
      float currLoc_Y;
      float currLoc_Z;


      //Multiply by a value to recipricate similar gravity as projectile
      gravity*=2;

      getViewPosition(&currLoc_X, &currLoc_Y, &currLoc_Z);
      currLoc_Y+=gravity; //Works because values are inherently Negative


      setViewPosition(currLoc_X, currLoc_Y, currLoc_Z);
      currLoc_X*=-1;
      currLoc_Y*=-1;
      currLoc_Z*=-1;  



      //Call Collision Responds Manually, as it does not get Called
      //unless provided keyboard input. Therefore fix via manual invoction
      //Collision Code:
      collisionResponse();
   }



int main(int argc, char** argv)
{
int i, j, k;
   /* initialize the graphics system */
   graphicsInit(&argc, argv);

   /* the first part of this if statement builds a sample */
   /* world which will be used for testing */
   /* DO NOT remove this code. */
   /* Put your code in the else statment below */
   /* The testworld is only guaranteed to work with a world of
      with dimensions of 100,50,100. */
   if (testWorld == 1) {
   /* initialize world to empty */
      for(i=0; i<WORLDX; i++)
         for(j=0; j<WORLDY; j++)
            for(k=0; k<WORLDZ; k++)
               world[i][j][k] = 0;

   /* some sample objects */
   /* build a red platform */
      for(i=0; i<WORLDX; i++) {
         for(j=0; j<WORLDZ; j++) {
            world[i][24][j] = 3;
         }
      }
   /* create some green and blue cubes */
      world[50][25][50] = 1;
      world[49][25][50] = 1;
      world[49][26][50] = 1;
      world[52][25][52] = 2;
      world[52][26][52] = 2;

   /* blue box shows xy bounds of the world */
      for(i=0; i<WORLDX-1; i++) {
         world[i][25][0] = 2;
         world[i][25][WORLDZ-1] = 2;
      }
      for(i=0; i<WORLDZ-1; i++) {
         world[0][25][i] = 2;
         world[WORLDX-1][25][i] = 2;
      }

   /* create two sample mobs */
   /* these are animated in the update() function */
      createMob(0, 50.0, 25.0, 52.0, 0.0);
      createMob(1, 50.0, 25.0, 52.0, 0.0);

   /* create sample player */
      createPlayer(0, 52.0, 27.0, 52.0, 0.0);

   } 
   else 
   {
      //We are the Server
      if(netServer==1)
      {
         //The World Building Logic
         //Second Implementations
         int seed = 10;

         //Method 2
         Gradient_Table gradientTable = CreateGradientTable(seed);

         //Nice Seed Values Range between ~20-60. 70 Becomes very Flat
         //Use 10 if you wish to check the collision for the No hopping on Tiles with Height difference of 2.
         //Use 2 For REALLY Jagged Array
         //Use 25 for Nice Valley type.
         float detailModifier =15;

         //For now Ensure that WORLDX == WORLDZ and that SIZE == WORLDX * WORLDZ
         for(int x=0;x<WORLDX;x++)
            {
               printf("\n");
               for(int z=0;z<WORLDZ;z++)
               {

                  //Method 1
                  //float val=PerlinNoise_At((float)(x+seed),(float)z+seed) *30 +25;
                  
                  //Method 2. The * modifier = Amplitude. DetailModifier= Frequency. Seed = Slight repositioning
                  //Octaves are implied.
                  float val=ComputePerlin_Value(gradientTable, (float)(x)/detailModifier +seed, (float)(z)/detailModifier +seed)  *25+25;


                  //Set Cubes to Land!
                  for(int i=0;i<val;i++)
                     world[x][i][z]=1;
               }
            }

         //Method 2
         //Gradient Table no longer needed so lets scrap it.
         DestroyGradientTable(gradientTable);

         //Lets Create some Clouds
         CreateSkyClouds();

         //Setup ProjectileManager
         CreateProjectileManager();
         CreatePlayerManager();
         Initialize_Server();
      }
      //We are the Client
      else if (netClient==1)
      {
        //Players do Not use Physics so they do not have a Projectile Manager
        //They can do clouds though to save on update messages (still synced)
         Initialize_Client();

      }


   }



	/* starts the graphics processing loop */
	/* code after this will not run until the program exits */
   glutMainLoop();
   return 0; 
}

   //Code where Destroy Code should be placed on proper Exits.
   //Graphics.c Enters this function via Keyboard Q
   void ExitCleanUpCode()
   {
      //Lets Avoid MemoryLeaks :) 
      //Cleanup after self. 
      DestroySkyClouds();
      DestroyProjectileManager(); 


   }


int oldX;
int oldY;


        //SpawnProjectile(xForce,yForce,zForce);

void mouse(int button, int state, int x, int y) {

   //This Only Occurs Client Side
   if(netClient==1)
   {

    
      if ((state == GLUT_DOWN) && (button == GLUT_LEFT_BUTTON))
      { 
         //All that is needed is to take our current XZ orientation
         //and determine the upward Y force which we will decay over time in ApplyGravity

         //Note Gravity plays no effect on X or Z force, instead wind would naturally have a
         //friction coefficient to reduce these values, but we will assume those are negligible

         //M_PI is pi defined in math.h
         //printf("Pi = %f\n", M_PI);
         long double radianAngle = (long double)projectile_Angle * M_PI/180.0; 

      //Soh Cah Toa
         //Calculate Y and Horizontal Force
         double xzForce= (double)(cos(radianAngle)) * projectile_Velocity;
         double yForce= (double)(sin(radianAngle)) * projectile_Velocity;


        //Now to apply our xz force in the direction we are facing
         float orientationX;
         float orientationY;
         float orientationZ;

         getViewOrientation(&orientationX,&orientationY,&orientationZ);

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

        shootFlag= TRUE;
        //Now we have all the variables to Spawn our projectile
        //But We Don't. Instead we Send the Message to the Server

        //SpawnProjectile(xForce,yForce,zForce);

        //char* message;
        //message= strdup("I want to Shoot a Projectile! :D\n");
        //send(client_SockFD, message, strlen(message), 0); 
      }

      if ((state == GLUT_UP) && (button == GLUT_RIGHT_BUTTON))
      {  
            //Calculate The Difference in X
            // ->  = Increase Velocity
         int   xDifference = x-oldX;
         float yDifference = y-oldY;

         //Compact the y Difference so smaller angles are achievable
         yDifference /= 10.0;
         xDifference /= 10.0;
         //Display Currently Set Velocity and Angle

         //Height is Inverted
         projectile_Angle    -= (double)(yDifference);

         projectile_Velocity += (double)(xDifference);

         //Max Angle = 180;
         if(projectile_Angle>90)
            projectile_Angle=90;
         if(projectile_Angle<0)
            projectile_Angle=0;

         if(projectile_Velocity<0)
            projectile_Velocity=0;
         if(projectile_Velocity>100)
            projectile_Velocity=100;

         //Max Velocity = 100
         //Warp the Mouse position to old position to make it easier to modify values 
         //and navigate
         glutWarpPointer( oldX, oldY);
              //Scale down the Projectile Force Between a Range

        //Find the Sweet Spot for Arcs ie if Mass = 5 *2 = Gravity will push down with a Force of 10
        //XZ should equate to a force of 20 in this instance min
        printf("----------\n");
        printf("Angle=%f\n", projectile_Angle);
        printf("Velocity=%f\n", projectile_Velocity);
        printf("===========\n");
      }
      else if ((state == GLUT_DOWN) && (button == GLUT_RIGHT_BUTTON))
      {
         oldX=x;
         oldY=y;
         //printf("down - %d,%d \n",x,y);
      }
   }
}
























