// There are n students in a class numbered from 0 to n - 1. The teacher will give each student a problem starting with the student number 0, then the student number 1, and so on until the teacher reaches the student number n - 1. After that, the teacher will restart the process, starting with the student number 0 again.
//
// You are given a 0-indexed integer array chalk and an integer k. There are initially k pieces of chalk. When the student number i is given a problem to solve, they will use chalk[i] pieces of chalk to solve that problem. However, if the current number of chalk pieces is strictly less than chalk[i], then the student number i will be asked to replace the chalk.
//
// Return the index of the student that will replace the chalk.
//

class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long s = 0, n = chalk.size();
        vector<long long> pres(n);
        for (int i = 0; i < n; i++) {
            s += chalk[i];
            pres[i] = (i == 0 ? 0 : pres[i-1]) + chalk[i];
        }
        int m = k / s;
        k -= m * s;
        for (int i = 0; i < n; i++) {
            if (k < pres[i]) {
                return i;
            }
        }
        return -1;
    }
};
