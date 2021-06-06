// Given two n x n binary matrices mat and target, return true if it is
// possible to make mat equal to target by rotating mat in 90-degree increments,
// or false otherwise.
//

class Solution {
public:
    vector<vector<int>> rotate(vector<vector<int>> &target) {
        vector<vector<int>> res(target.size(), vector<int>(target.size(), 0));
        for (int i = 0; i < res.size(); i++) {
            for (int j = 0; j < res[i].size(); j++) {
                res[i][j] = target[j][target.size() - i - 1];
            }
        }
        return res;
    }

    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        for (int i = 0; i < 4; i++) {
            target = rotate(target);
            if (mat == target) {
                return true;
            }
        }
        return false;
    }
};
