// You are given a 0-indexed binary string s and two integers minJump and maxJump. In the beginning, you are standing at index 0, which is equal to '0'. You can move from index i to index j if the following conditions are fulfilled:
//
// i + minJump <= j <= min(i + maxJump, s.length - 1), and
// s[j] == '0'.
// Return true if you can reach index s.length - 1 in s, or false otherwise.
//

class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        queue<int> q;
        q.push(0);
        int idx = 0;
        while (!q.empty()) {
            auto i = q.front();
            q.pop();
            for (int j = max(i + minJump, idx + 1); j <= min(i + maxJump, (int)s.length() - 1); j++) {
                if (j == s.length() - 1 && s[j] == '0') {
                    return true;
                }
                if (s[j] == '0') {
                    q.push(j);
                }
            }
            idx = min(i + maxJump, (int)s.length() - 1);
        }
        return false;
    }
};
