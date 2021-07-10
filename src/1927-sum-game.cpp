// Alice and Bob take turns playing a game, with Alice starting first.
//
// You are given a string num of even length consisting of digits and '?' characters. On each turn, a player will do the following if there is still at least one '?' in num:
//
// Choose an index i where num[i] == '?'.
// Replace num[i] with any digit between '0' and '9'.
// The game ends when there are no more '?' characters in num.
//
// For Bob to win, the sum of the digits in the first half of num must be equal to the sum of the digits in the second half. For Alice to win, the sums must not be equal.
//
// For example, if the game ended with num = "243801", then Bob wins because 2+4+3 = 8+0+1. If the game ended with num = "243803", then Alice wins because 2+4+3 != 8+0+3.
// Assuming Alice and Bob play optimally, return true if Alice will win and false if Bob will win.

class Solution {
public:
    bool sumGame(string num) {
        int n = num.length(), half = n / 2;
        int s1 = 0, s2 = 0, cnt1 = 0, cnt2 = 0;
        for (int i = 0; i < half; i++) {
            if (num[i] == '?') {
                cnt1++;
            } else {
                s1 += num[i] - '0';
            }
        }
        for (int i = half; i < n; i++) {
            if (num[i] == '?') {
                cnt2++;
            } else {
                s2 += num[i] - '0';
            }
        }
        if (cnt1 + cnt2 == 0) {
            return s1 != s2;
        } 
        if ((cnt1 + cnt2) % 2 == 1) {
            return true;
        }
        if (cnt1 == cnt2 && s1 == s2) {
            return false;
        }
        if ((cnt1 > cnt2 && s1 > s2) || (cnt1 < cnt2 && s1 < s2)) {
            return true;
        }
        return cnt1 > cnt2 ? s2 - s1 != (cnt1 - cnt2) / 2 * 9 : s1 - s2 != (cnt2 - cnt1) / 2 * 9;
    }
};


// elegant solution by AinuYu
class Solution {
public:
    bool sumGame(string num) {
        int n = num.length(), x = 0, a = 0, b = 0;
        for (int i = 0; i < n / 2; i++) {
            num[i] == '?' ? a++ : x += num[i] - '0';
        }
        for (int i = n / 2; i < n; i++) {
            num[i] == '?' ? b++ : x -= num[i] - '0';
        }
        if (a + b & 1) {
            return true;
        }
        return x - 9 * b + (a + b) / 2 * 9;
    }
};
