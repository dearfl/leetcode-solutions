// Given a string s, determine if it is a palindrome, considering only
// alphanumeric characters and ignoring cases.
//
//  Example 1:
//
//  Input: s = "A man, a plan, a canal: Panama"
//  Output: true
//  Explanation: "amanaplanacanalpanama" is a palindrome.
//  Example 2:
//
//  Input: s = "race a car"
//  Output: false
//  Explanation: "raceacar" is not a palindrome.

//#include <bits/stdc++.h>
//
//using namespace std;
//
//bool isPalindrome(string s) {
//    vector<char> vec;
//    for (auto &c : s) {
//        if (isalpha(c) || isdigit(c)) {
//            vec.push_back(tolower(c));
//        }
//    }
//    if (vec.empty()) {
//        return true;
//    }
//    for (auto l = vec.begin(), r = vec.end() - 1; l < r; ++l, --r) {
//        if (*l != *r) {
//            return false;
//        }
//    }
//    return true;
//}
//
//int main() {
//    return 0;
//}
//

class Solution {
public:
    bool isPalindrome(string s) {
        for (int l = 0, r = s.length() - 1; l < r; ) {
            while (l < r && !isalnum(s[l])) l++;
            while (l < r && !isalnum(s[r])) r--;
            if (tolower(s[l++]) != tolower(s[r--])) {
                return false;
            }
        }
        return true;
    }
};
