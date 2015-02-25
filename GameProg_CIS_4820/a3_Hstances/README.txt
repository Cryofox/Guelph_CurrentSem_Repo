Horia “Ryder” Stancescu
hstances - 0721385

To Compile: make

To Compile/Launch: make run

TO RUN (after compiled): ./a1

To Remove OBJS + Exe: make clean

FOR TA MARKING ON LAB MACS:
    The lab macs are DEFAULTED to have the right button defaulted to Primary. 
    In order to use the Right Mouse button your profile must allow for it on the mac.
    Simply go to System Preferences -> Mouse -> (Change Right button to Secondary).


A2 ReadME:
A lot of changes were made:

    Projectile Code - Added and split into respective .c and .h Code

    a1.c  Graphics.c functions have a prototype made in graphics .h meaning
        most of the externs were no longer needed thus removed.

    Projectiles launch based on Velocity/Angle. Therefore if a large velocity is used, the arc will be 
        very small, if a low velocity is used, the projectile will 


Whats Implemented:
    Time, Projectiles, Collision are all applied.

    Collision Works as Demonstrated in the Spec. Note if you press Left mouse button and don't see a projectile
    check the Angle as odds are the angle is set to 0 and velocity is low meaning the ball falls straight down,
    or the angle is high and you may need to look upward to see the projectile as it arcs.

How Collision Works:
        
    When the "mob" is detected to be colliding with a cube, a blast occurs in all directions
    mimicking the following pattern where [x] symbolizes the blast point:

            x
          x x x
        x x[x]x x
          x x x
            x 
    This will  eliminate all cubes in the direction provided along with any cubes within the blast radius
        thus providing a more "blast" like collision.



How Projectiles Work:
    When a Projectile is needed the Force is calculated and Spawn Projectile is called, this 
    alerts projectile Manager that it needs to check if room for an additional projectile exists
    if it does create a projectile with the specified force at the players position.

    During Update, the projectilemanager is told to apply all forces relative to time passed on ALL projectiles,
    this in turn updates the visible "mob" by calling CreateMob, which aside from the provided name does not create 
    mobs, instead it Sets a mob to visible and updates its position, thus this is why the function is used over
    set position, it autohandles the visibility.

    If a projectile collides, apply the blast radius if the collision was with a block,
    delete the projectile, and toggle the mob to not visible.

    Deleting a projectile works by finding the index of the projectile which collided, and freeing the structs memory,
    all projectiles in projectile manager from that index onward are shifted left by 1, and the projectile_Count is 
    decremented to reflect the next available location a projectile struct can be created on.

    When a projectile is created the ID is gathered by navigating through the array and checking all values
    between 0 and maxProjectiles= MOB_count;

        This is done due to the potential possibility:
            Projectile Array :  0, 1, 2, 3, 4, 5
            projectile 3 collides
            Projectile array :  0, 1, 2, 4, 5

            New Projectile Requested
            Check: 0? No, 1? No, 2? No, 3
            Projectile array :  0, 1, 2, 4, 5, 3


How Time Work:
    All time is calculated by taking the differential between current Update and Last.
    This elapsed time or timePassed variable is then passed to all functions which manipulate the game
    environment such as: 
                        Clouds (Movement)
                        Player-Gravity (Dropping Player)
                        Projectiles (Force and Gravity)
                        



    





