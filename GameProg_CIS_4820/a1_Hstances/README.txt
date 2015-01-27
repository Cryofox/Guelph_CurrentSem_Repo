Horia “Ryder” Stancescu
hstance - 0721385

To Compile: make

To Compile/Launch: make run

TO RUN (after compiled): ./a1

To Remove OBJS + Exe: make clean

Below you will find lengthy explanation to accompany commented code within the .c files.
This is all done for the benefit of you understanding the code, what it's doing, why it's done that way
and the higher likelihood that I the student don't get burned by pissing off you the 
all mighty god of marks! *bow* (゜ヮ゜)

Also alot of effort went into this and it runs so nice, all it's missing is a bow. 
Below I'm trying to explain myself in a rather boring/formal manner, 
if you'd like more laid black slacker wording for future readmes, just let me know. 


(-'๏_๏'-)

Explanation for Features:
——————————————————————————
Perlin Noise - Implemented x2.

This one was tricky. I implemented it twice to get two entirely different types of Perlin noise, the first one was from the course Website (not used for demo but implemented if you the TA wish to see it). The second one was true perlin, as in it utilizes dot product AND vector gradient with permutation table to achieve results this one is closest to the article written by Ken Perlin, it is a bit more math heavy tho.

Method 2 [Default]:
The Code for this method is in perlin2.c (Again this is the DEFAULT perlin chosen)

	This method is the one chosen for marking as it produces very nice gradual slopes depending on the detail modifier chosen.
	
	To Change the results given, on line 322: detail modifier, simply alter this value.

	For testing collisiion you’ll want some jagged surfaces a value of 10 produces more steep inclines while remaining pleasant,
	however for entirely  spikey maps a value of 2 will work. 1 will = flat as dividing by 1= an integer value. Do not use 
	0 as this will cause divide by zero.


To Run Method one of Perlin: in a1.c 
The Code for this method is in perlin1.c 

	Go to Line:332 and uncomment the line
	//float val=PerlinNoise_At((float)(x+seed),(float)z+seed) *30 +25;
	^ Remove the //
	Then, on line 336 Comment it
	float val=ComputePerlin_Value(gradientTable, (float)(x)/detailModifier +seed, (float)(z)/detailModifier +seed)  *25+25;

Then type make and run ./a1, to see the results for Method 1. To change the values affecting the results, in
perlin.c Modify Octave, Amplitude, and Frequency. As these control Method 1.


Website for Method1: 	http://freespace.virgin.net/hugo.elias/models/m_perlin.htm
Method 1 Explained: True perlin does not use Octaves this is used by fractal noise algorithms such as FBM Fractal Brownian Motion,
this method of “perlin” is the one based from the prescribed website. The results imo are quite lame and as such I have chosen to leave this within the code incase you wish to mark a noise algorithm similar to this.

Website for Method2:   //http://www.angelcode.com/dev/perlin/perlin.html
Method 2 Explained: TRUE PERLIN! This does NOT use Octaves, instead like Ken Perlins original algorithm it utilizes a permutation table, and gradient vectors (a directional vector) to imply slope direction. This is then Interpolated, in this method Bi-Cubic interpolation is used, it’s commented, and quite math heavy. The Steps of the algorithm are commented to ease confusion, as to the variable names and actual behind the scenes math, try to bear with it as they are almost pure math. Basically it works as such, create directional arrows at integer locations, then given an “input” find its height based upon its surrounding 4 integer vector arrows and interpolate the results. Since the results are permutated/re-arranged, this creates perlin noise.

==========================



Gravity - Implemented
——————————————————————————

The Gravity code works as such: always apply -1.1 downward force, then call the CollisionResponse.

==========================



Collision - Implemented
——————————————————————————

To get this function to work nicely, a change was needed to graphics.c. 
The change is in the function:
void setViewPosition(float x, float y, float z) {
   //Added Code//
   oldvpx= vpx;
   oldvpy= vpy;
   oldvpz= vpz;
   ///////////
   vpx = x;
   vpy = y;
   vpz = z;
}

This code was added so that when a new viewPosition is set, the old one keeps up to date, instead of 
the way it was handled before (old position only updates on keyboard press).

With this change, you can see that gravity applying a new position, makes it easy to detect the direction our
view or anything for that matter was heading in, and to create collision code to counteract.

It works as so, if we are entering A block, check if another block exists above A block, 
if not thats where we are going.
if so, stop moving.

This works perfectly in that we the player do NOT move inside blocks, HOWEVER the view CAN CULL into it. 
Because the view is a rectangle if you view a wall dead on, that’s all you get a wall, however if one of the corners
of the view were to clip its way in, you now get a type of “x-ray” vision inside this block partially, however you will not be
able to move into it. 

Second the starting position tends to land the character at a perfect corner (weird I know). Fret not
you are NOT falling through the map, you view just lands in the above mentioned clipping area, simply moving your character
or rotating your view will show you this.

==========================

Clouds - Implemented
——————————————————————————

Clouds are created via structs. 

The code is well documented, simply call CreateSkyClouds() to setup the clouds, and then    void UpdateCloudMovement() to animate them.

The creation works in a manner similar to dyjkstras patching algorithm, basically given a centre node, randomly add neighbours to this node, when a neighbour gets added restart at the start of the list until the size is reached. Add a duplication checker to ensure a spot does not get counted twice and boom Abstract clouds.


To animate the clouds, simply apply the wind force on the clouds centroid/center location, since the voxels making it up are all offsets from 0,0,0. All that is required is to  add the CentrLocation + VoxelOffset, to get the location of the cube. By Modding this value to the world array, you now have clouds which wrap around the sky take a look its quite cool.

Finally All these structs and pointers can be fatal if not cleaned, therefore in graphics.c on line 516, an ExitCleanUpCode() function is
added, this initiates the Cloud Destroying code to free all structs/pointers when the program is exited normally (by pressing q). The Function is located in a1.c. The DestroySkyClouds() 
function is obviously located in clouds.c along with all other cloud related functions.

==========================

Controls:
For Cloud Controls:
clouds.c line 15-20
	//The number of Clouds you'd like to populate the world
	int num_Clouds=30;
	int max_CloudSize=30;

	//These Values are used to manipulate the direction wind is applied in, used for Cloud Movement
	//Diagonal movements may cause jittering due to centroid + mod
	float windForce_X=0;
	float windForce_Z=0.1;

For Gravity Controls:
a1.c line 233
      float gravity = .1;


For Perlin Controls:
Method 1&2:
a1.c line 313
      int seed = 10;

Method 2:

a1.c line 322
      float detailModifier =15;


Method 1:(Should you choose to use it)

a1.c line 22-33
      float gain = 0.65;		
      float height = 0;		
     //This is the persistance value to be used throughout the Perlin program		
      //This determines the lowest or max detail an object can reach. 1=High Detail, 1/4= Low Detail.		
      float persistence = 0.5f; // 1/2		
		
      //How often to loop through the array		
      int num_Octaves = 15; 		
			
      float frequency = 1.0f/((float)WORLDX/2);		
      float amplitude = gain;   





	
That is all.

Hopefully my commented code and this Readme are enough of a guide to get you through the code.
If a function is missing some comment as to its use, check the .h file, as it might be listed there.
