// Implement strStr().
// Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

// Example 1:
// Input: haystack = "hello", needle = "ll"
// Output: 2

// Example 2:
// Input: haystack = "aaaaa", needle = "bba"
// Output: -1

// Clarification:
// What should we return when needle is an empty string? This is a great question to ask during an interview.
// For the purpose of this problem, we will return 0 when needle is an empty string. This is consistent to C's strstr() and Java's indexOf().
//

//1st sub wrong ans
class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) {
            return 0;
        }
        for (int i = 0; i <= haystack.length() - needle.length(); i++) { // !the problem is in this line
            if (haystack[i] == needle[0]) {
                bool flag = true;
                for (int j = 1; j < needle.length(); j++) {
                    if (haystack[i + j] != needle[j]) {
                        flag = false;
                        break;
                    }
                }
                if (flag) {
                    return i;
                }
            }
        }
        return -1;
    }
};

// correct ans
class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) {
            return 0;
        }
        for (int i = 0; i + needle.length() <= haystack.length(); i++) {
            if (haystack[i] == needle[0]) {
                bool flag = true;
                for (int j = 1; j < needle.length(); j++) {
                    if (haystack[i + j] != needle[j]) {
                        flag = false;
                        break;
                    }
                }
                if (flag) {
                    return i;
                }
            }
        }
        return -1;
    }
};

// somewhat elegant solution
class Solution {
public:
    int strStr(string haystack, string needle) {
        for (int i = 0; ; i++) {
            for (int j = 0; ; j++) {
                if (j == needle.length()) {
                    return i;
                }
                if (i + j == haystack.length()) {
                    return -1;
                }
                if (needle[j] != haystack[i + j]) {
                    break;
                }
            }
        }
    }
};
