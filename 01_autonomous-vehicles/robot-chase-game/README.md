<<<<<<< HEAD
# Computer_Vision

Essential OpenCV reference/functions for Computer Vision in 
1. C++ 
2. Python (To be done)

Code includes methods for:-
1. Image Processing (Image Dilation, Erosion, Smoothing)
2. Webcam stream processing
3. Webcam Object Detection
4. Webcam Object Tracking
5. Image Shape Detection
=======

# Robot Chasing Game
- In this simple game, a team of computer controlled AI robots chase the human controlled robot in an arena.
- The user is required to move the human controlled robot outside the arena and avoid being caught by the computer controlled robots
- If the computer controlled robots and human controlled robots are at the same location, then the game terminates
- The size of the arena is 22x14
- Each robot has position information of the form (x,y,dir), where x and y are the positions in the field while dir is the direction that the robot faces.
	- dir can take the value of 'n','s','e' and 'w' corresponding to north, south, east and west

To run the game:-
1) Enter *mkdir build* to create a build folder
2) Enter *cd build* on the terminal
3) Enter *cmake ..* to generate the make file
4) Enter *make all* to compile the program
5) Enter *./game* to launch the game on terminal

After this, in order to play the game:-
1) Enter the number of robots (non human controlled) that is desired
2) Enter x,y and dir positions. **Note that x and y are integers such that x must lie between 0 and 13 (both inclusive) and y must lie between 0 and 21.** It also follows the orientation given below,

Field definitions
 	0 1 2 3 4 5 6 . . x(13)>
 0
 1
 2
 3
 4
 5
 6
 .
 .
 y(21) 

**dir is the direction and must take values 'n','s','e' and 'w'.**

3) Enter the above directions for the human controlled robot first and then the other robots
4) To move the robot, only enter **forward, backward, right or left**.
>>>>>>> rcg/main
