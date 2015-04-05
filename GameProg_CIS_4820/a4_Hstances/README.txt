Horia “Ryder” Stancescu
hstances - 0721385

To Compile: make

To Compile/Launch: make run

TO RUN (after compiled): ./a1

To Remove OBJS + Exe: make clean


Alright no more networks! Although having an AI might make it harder for you
the TA to test. I’ll write how the algorithm additions work for your
testing to be that much easier.

Since all implementations are to be tested without networking, simply typing
make run will set you up with 1 enemy and yourself.

Or typeing: ./a1
with no -client/server flags.


Next AI: I’ve went through hell to align the enemy to face the exact direction he is looking. Meaning you can test Line of Sight by hiding behind some blocks, if a line can’t be drawn to you, the enemy won’t see you, and he won’t shoot you. When the AI DOES see you however, I’ve implemented a 1 second delay between it firing shots. The reason is, it will constantly spam max projectiles at you otherwise.


AI Firing: The AI Looks in the direction it is facing and moving, however it shoots is offset by the direction it is facing. The reason is, A) the spec doesn’t say the mob must look where it is shooting, just looking and moving, and B) if it did look where it shot, since it shoots at you, you will never be able to test the 180 Field of View which IS implemented in the code.

AI Line of Sight:  
1-180 Degree Field of View Arc, if you are infant it may be able to see you
2-50 Block Radius, if you are within 50 units of the mob it may be able to see you
3-Finally, if it can draw a line from it’s center to the player’s center, and steps 1 and 2 were true, than the mob can see you and will fire every 2 seconds at the player.


Direct vs InDirect Hits: These messages are printed when a projectile explodes in proximity of an ai or player. Meaning if you the player shoot a projectile at yourself, you could cause DIRECT hits on yourself, same with the AI. You can use this to make testing the Direct and Indirect hits that much easier.


AI Dodge - When you fire a shot, regardless if it will hit the AI or not, the AI will move forward for 2 seconds before attempting to shoot at you again. If you shoot before it can, it will “Dodge” by moving forward again, until either LOS (line of sight) is broken, or you stop firing meaning it will constantly fire at you.


Finally, Wandering. The AI wanders by choosing a random location on the map and trying to move to it directly, this spot changes every 3 seconds giving the illusion of the mob wandering, since the locations are random the mob can potentially move everywhere and anywhere on the map given the terrain.

Jump - To jump press space, as the spec does not say anything against jumping while falling, you CAN jump when you fall. However you may not jump more than once every 5 seconds. You can jump 2 cubes high and then gravity will pull you down. 





As you can see here in the readme, in the code, and when you run the program, all features have been coded to specification. However I must state this, even though in the code the AI will not move into a location occupied by the player, it’s probably impossible for you to test this because it will involve you jumping in the way of the Enemy, meaning as soon as you do, it will halt to shoot at you. If you truly want to test this, I recommend jumping in front of the AI (as its dodge routine is simply to move forward), and then shoot until it walks into you. You will notice it halts and does not continue moving. Also in testing Wandering I recommend pressing the 1 key, as it can allow you to see the mob moving without your presence interfering.
                        



    





