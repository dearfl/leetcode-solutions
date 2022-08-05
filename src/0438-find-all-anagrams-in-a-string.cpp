/*
Given two strings s and p, return an array of all the start indices of p's anagrams in s. You may return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

Example 1:
    Input: s = "cbaebabacd", p = "abc"
    Output: [0,6]
    Explanation:
        The substring with start index = 0 is "cba", which is an anagram of "abc".
        The substring with start index = 6 is "bac", which is an anagram of "abc".
Example 2:
    Input: s = "abab", p = "ab"
    Output: [0,1,2]
    Explanation:
        The substring with start index = 0 is "ab", which is an anagram of "ab".
        The substring with start index = 1 is "ba", which is an anagram of "ab".
        The substring with start index = 2 is "ab", which is an anagram of "ab".

Constraints:
    1 <= s.length, p.length <= 3 * 10^4
    s and p consist of lowercase English letters.
*/

// naive counting solution
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res, pcnt(26);
        vector<vector<int>> cnt(s.length() + 1, vector<int>(26));
        for (int i = 0; i < s.length(); i++) {
            for (int j = 0; j < 26; j++) {
                cnt[i+1][j] = cnt[i][j];
            }
            cnt[i+1][s[i] - 'a'] += 1;
        }
        for (int i = 0; i < p.length(); i++) {
            pcnt[p[i] - 'a'] += 1;
        }
        for (int i = 0; i + p.length() <= s.length(); i++) {
            bool flag = true;
            for (int j = 0; j < 26; j++) {
                int k = cnt[i+p.length()][j] - cnt[i][j];
                if (k != pcnt[j]) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                res.push_back(i);
            }
        }
        return res;
    }
};

// more concise sliding window impl, no time complexity advantage
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res, pc(26), sc(26);
        if (s.length() < p.length()) {
            return res;
        }
        for (int i = 0; i < p.length(); i++) {
            pc[p[i]-'a']++;
            sc[s[i]-'a']++;
        }
        if (pc == sc) {
            res.push_back(0);
        }
        for (int i = p.length(); i < s.length(); i++) {
            sc[s[i]-'a']++;
            sc[s[i-p.length()]-'a']--;
            if (pc == sc) {
                res.push_back(i - p.length() + 1);
            }
        }
        return res;
    }
};

