// There is a malfunctioning keyboard where some letter keys do not work. All other keys on the keyboard work properly.
//
// Given a string text of words separated by a single space (no leading or trailing spaces) and a string brokenLetters of all distinct letter keys that are broken, return the number of words in text you can fully type using this keyboard.
//

class Solution {
public:
    int canBeTypedWords(string text, string l) {
        int ans = 0;
        bool flag = true;
        for (int i = 0; i <= text.size(); i++) {
            if (i == text.size() || text[i] == ' ') {
                if (flag) {
                    ans++;
                }
                flag = true;
            } else if (l.find(text[i]) != -1) {
                flag = false;
            }
        }
        return ans;
    }
};
