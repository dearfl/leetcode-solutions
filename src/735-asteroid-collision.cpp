// We are given an array asteroids of integers representing asteroids in a row.
//
// For each asteroid, the absolute value represents its size, and the sign represents its direction (positive meaning right, negative meaning left). Each asteroid moves at the same speed.
//
// Find out the state of the asteroids after all collisions. If two asteroids meet, the smaller one will explode. If both are the same size, both will explode. Two asteroids moving in the same direction will never meet.

// elegant solution by alexander
// 爷被这个题目折磨了，一开始是思路错了，后来有了正确的思路还是写不对。。。爷哭了

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        for (int i = 0; i < asteroids.size(); i++) {
            if (asteroids[i] > 0 || ans.empty() || ans.back() < 0) {
                ans.push_back(asteroids[i]);
            } else if (ans.back() <= -asteroids[i]) {
                if (ans.back() < -asteroids[i]) {
                    i--;
                }
                ans.pop_back();
            }
        }
        return ans;
    }
};
