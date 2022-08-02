/*
Given a string s and a string array dictionary, return the longest string in the dictionary that can be formed by deleting some of the given string characters. If there is more than one possible result, return the longest word with the smallest lexicographical order. If there is no possible result, return the empty string.

Example 1:
    Input: s = "abpcplea", dictionary = ["ale","apple","monkey","plea"]
    Output: "apple"

Example 2:
    Input: s = "abpcplea", dictionary = ["a","b","c"]
    Output: "a"

Constraints:
    1 <= s.length <= 1000
    1 <= dictionary.length <= 1000
    1 <= dictionary[i].length <= 1000
    s and dictionary[i] consist of lowercase English letters.
*/

class Solution {
public:
    bool helper(const string s1, const string s2) {
        int i = 0, j = 0;
        for (; i < s1.length() && j < s2.length(); j++) {
            if (s1[i] == s2[j]) {
                i++;
            }
        }
        return i == s1.length();
    }
    
    string findLongestWord(string s, vector<string>& dict) {
        sort(dict.begin(), dict.end(), [](string s1, string s2) {
            return s1.length() > s2.length() || s1.length() == s2.length() && s1 < s2;
        });
        for (const auto &d : dict) {
            if (helper(d, s)) {
                return d;
            }
        }
        return "";
    }
};
