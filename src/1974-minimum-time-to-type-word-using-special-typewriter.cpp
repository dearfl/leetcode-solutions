// There is a special typewriter with lowercase English letters 'a' to 'z' arranged in a circle with a pointer. A character can only be typed if the pointer is pointing to that character. The pointer is initially pointing to the character 'a'.
//
//
// Each second, you may perform one of the following operations:
//
// Move the pointer one character counterclockwise or clockwise.
// Type the character the pointer is currently on.
// Given a string word, return the minimum number of seconds to type out the characters in word.
//

class Solution {
public:
    int minTimeToType(string word) {
        int idx = 0, ans = 0;
        for (const auto c : word) {
            int next = c - 'a';
            ans += idx > next ? min(idx - next, next + 26 - idx) : min(next - idx, idx + 26 - next);
            ans++;
            idx = next;
        }
        return ans;
    }
};
