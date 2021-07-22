// Given an array target and an integer n. In each iteration, you will read a number from  list = {1,2,3..., n}.
//
// Build the target array using the following operations:
//
// Push: Read a new element from the beginning list, and push it in the array.
// Pop: delete the last element of the array.
// If the target array is already built, stop reading more elements.
// Return the operations to build the target array. You are guaranteed that the answer is unique.
//

class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        int idx = 1, len = 0;
        while (len < target.size()) {
            ans.push_back("Push");
            if (target[len] != idx) {
                ans.push_back("Pop");
                len--;
            }
            len++;
            idx++;
        }
        return ans;
    }
};
