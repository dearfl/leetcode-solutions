// Given a string s and an array of strings words, determine whether s is a prefix string of words.
//
// A string s is a prefix string of words if s can be made by concatenating the first k strings in words for some positive k no larger than words.length.
//
// Return true if s is a prefix string of words, or false otherwise.
//

ass Solution {
public:
    bool isPrefixString(string s, vector<string>& words) {
        for (const string str : words) {
            if (s.empty()) {
                break;
            }
            string k = s.substr(0, str.length());
            if (k != str) {
                return false;
            }
            s = s.substr(str.length());
        }
        return s.empty();
    }
};
