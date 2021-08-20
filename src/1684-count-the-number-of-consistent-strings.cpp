// You are given a string allowed consisting of distinct characters and an array of strings words. A string is consistent if all characters in the string appear in the string allowed.
//
// Return the number of consistent strings in the array words.
//

class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int ans = 0, count[26] = { 0 };
        unordered_set<char> cs;
        for (const auto c : allowed) {
            cs.insert(c);
        }
        for (const auto &s : words) {
            memset(count, 0, sizeof(count));
            for (const auto c : s) {
                count[c - 'a']++;
            }
            bool flag = true;
            for (int i = 0; i < 26; i++) {
                if (cs.find('a' + i) == cs.end() && count[i] != 0) {
                    flag = false;
                    break;
                }
            }
            ans += flag;
        }
        return ans;
    }
};
