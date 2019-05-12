/*
	On an infinite plane, a robot initially stands at (0, 0) and faces north.  The robot can receive one of three instructions:

	"G": go straight 1 unit;
	"L": turn 90 degrees to the left;
	"R": turn 90 degress to the right.
	The robot performs the instructions given in order, and repeats them forever.

	Return true if and only if there exists a circle in the plane such that the robot never leaves the circle.

	 

	Example 1:

	Input: "GGLLGG"
	Output: true
	Explanation: 
	The robot moves from (0,0) to (0,2), turns 180 degrees, and then returns to (0,0).
	When repeating these instructions, the robot remains in the circle of radius 2 centered at the origin.
	Example 2:

	Input: "GG"
	Output: false
	Explanation: 
	The robot moves north indefinetely.
	Example 3:

	Input: "GL"
	Output: true
	Explanation: 
	The robot moves from (0, 0) -> (0, 1) -> (-1, 1) -> (-1, 0) -> (0, 0) -> ...
	 

	Note:

	1 <= instructions.length <= 100
	instructions[i] is in {'G', 'L', 'R'}
*/

class Solution {
public:
    bool isRobotBounded(string instructions) {

        int x=0,y=0;
        int dir = 0;
        // 0 : Up    1 : Right  2 : Down    3 : Left
        for(int i =0;i<4;i++){
            for(int j=0;j<instructions.size();j++){
                if(instructions[j] == 'G'){
                    switch(dir){
                        case 0:
                            y+=1;
                            break;
                        case 1:
                            x+=1;
                            break;
                        case 2:
                            y-=1;
                            break;
                        case 3:
                            x-=1;
                    }
                }
                else{
                    dir = Turn(dir,instructions[j]);
                }
            }
            if(x == 0 && y == 0)
                return true;
        }
        return false;

    }
    int Turn(int dir,char c){
        if(c == 'L')
            return (dir + 3)%4;
        else
            return (dir + 1)%4;
    }
};