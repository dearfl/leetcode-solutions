/*
A teacher is writing a test with n true/false questions, with 'T' denoting true and 'F' denoting false. He wants to confuse the students by maximizing the number of consecutive questions with the same answer (multiple trues or multiple falses in a row).

You are given a string answerKey, where answerKey[i] is the original answer to the ith question. In addition, you are given an integer k, the maximum number of times you may perform the following operation:

    Change the answer key for any question to 'T' or 'F' (i.e., set answerKey[i] to 'T' or 'F').

Return the maximum number of consecutive 'T's or 'F's in the answer key after performing the operation at most k times.

Example 1:
    Input: answerKey = "TTFF", k = 2
    Output: 4
    Explanation: We can replace both the 'F's with 'T's to make answerKey = "TTTT".
    There are four consecutive 'T's.
Example 2:
    Input: answerKey = "TFFT", k = 1
    Output: 3
    Explanation: We can replace the first 'T' with an 'F' to make answerKey = "FFFT".
    Alternatively, we can replace the second 'T' with an 'F' to make answerKey = "TFFF".
    In both cases, there are three consecutive 'F's.
Example 3:
    Input: answerKey = "TTFTTFTT", k = 1
    Output: 5
    Explanation: We can replace the first 'F' to make answerKey = "TTTTTFTT"
    Alternatively, we can replace the second 'F' to make answerKey = "TTFTTTTT". 
    In both cases, there are five consecutive 'T's.

Constraints:
    n == answerKey.length
    1 <= n <= 5 * 10^4
    answerKey[i] is either 'T' or 'F'
    1 <= k <= n
*/

class Solution {
public:
    int cnt[50002];
    bool helper(string t, int k, int n) {
        cnt[0] = 0;
        for (int i = 0; i < t.length() + 1; i++) {
            cnt[i + 1] = cnt[i];
            if (i != t.length() && t[i] == 'T') {
                cnt[i + 1]++;
            }
        }
        for (int i = n; i < t.length() + 1; i++) {
            int c = cnt[i] - cnt[i - n];
            if (c <= k || n - c <= k) {
                return true;
            }
        }
        return false;
    }
    
    int maxConsecutiveAnswers(string key, int k) {
        int l = 0, r = key.length() + 1;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (helper(key, k, mid)) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return max(l - 1, 0);
    }
};
