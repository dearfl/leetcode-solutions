// On an infinite plane, a robot initially stands at (0, 0) and faces north. The robot can receive one of three instructions:
//
// "G": go straight 1 unit;
// "L": turn 90 degrees to the left;
// "R": turn 90 degrees to the right.
// The robot performs the instructions given in order, and repeats them forever.
//
// Return true if and only if there exists a circle in the plane such that the robot never leaves the circle.
//

class Solution {
public:
    bool isRobotBounded(string instructions) {
        int dire[][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int idx = 0;
        int x = 0, y = 0;
        for (const auto c : instructions) {
            switch (c) {
                case 'G':
                    x += dire[idx][0];
                    y += dire[idx][1];
                    break;
                case 'L':
                    idx = (idx + 3) % 4;
                    break;
                case 'R':
                    idx = (idx + 1) % 4;
                    break;
            }
        }
        return !(idx == 0 && (x != 0 || y != 0)); 
    }
};
