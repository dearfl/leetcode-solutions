// You are given a string num, which represents a large integer. You are also given a 0-indexed integer array change of length 10 that maps each digit 0-9 to another digit. More formally, digit d maps to digit change[d].
//
// You may choose to mutate a single substring of num. To mutate a substring, replace each digit num[i] with the digit it maps to in change (i.e. replace num[i] with change[num[i]]).
//
// Return a string representing the largest possible integer after mutating (or choosing not to) a single substring of num.
//
// A substring is a contiguous sequence of characters within the string.
//

class Solution {
public:
    string maximumNumber(string num, vector<int>& change) {
        int idx = 0;
        while (idx < num.size() && change[num[idx] - '0'] <= num[idx] - '0') idx++;
        for ( ; idx < num.size(); idx++) {
            if (change[num[idx] - '0'] < num[idx] - '0') {
                break;
            }
            num[idx] = change[num[idx] - '0'] + '0';
        }
        return num;
    }
};
