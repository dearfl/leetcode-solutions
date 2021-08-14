// There is a survey that consists of n questions where each question's answer is either 0 (no) or 1 (yes).
//
// The survey was given to m students numbered from 0 to m - 1 and m mentors numbered from 0 to m - 1. The answers of the students are represented by a 2D integer array students where students[i] is an integer array that contains the answers of the ith student (0-indexed). The answers of the mentors are represented by a 2D integer array mentors where mentors[j] is an integer array that contains the answers of the jth mentor (0-indexed).
//
// Each student will be assigned to one mentor, and each mentor will have one student assigned to them. The compatibility score of a student-mentor pair is the number of answers that are the same for both the student and the mentor.
//
// For example, if the student's answers were [1, 0, 1] and the mentor's answers were [0, 0, 1], then their compatibility score is 2 because only the second and the third answers are the same.
// You are tasked with finding the optimal student-mentor pairings to maximize the sum of the compatibility scores.
//
// Given students and mentors, return the maximum compatibility score sum that can be achieved.
//

class Solution {
public:
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        int m = students.size(), n = students.back().size();
        int ans = 0, s = 0;
        vector<int> p(m);
        for (int i = 0; i < m; i++) {
            p[i] = i;
        }
        do {
            s = 0;
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    s += students[i][j] == mentors[p[i]][j];
                }
            }
            ans = max(ans, s);
        } while (next_permutation(p.begin(), p.end()));
        return ans;
    }
};

// bit mask solution
class Solution {
public:
    int cnt(unsigned int n) {
        int k = 0;
        while (n) {
            n &= n - 1;
            k++;
        }
        return k;
    }

    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        int m = students.size(), n = students.back().size();
        vector<unsigned> stu(m), men(m);
        unsigned kk = 0xFFFFFFFF << n;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                stu[i] <<= 1;
                stu[i] |= students[i][j];
                men[i] <<= 1;
                men[i] |= mentors[i][j] | kk;
            }
        }
        int ans = 0;
        vector<int> p(m);
        for (int i = 0; i < m; i++) {
            p[i] = i;
        }
        do {
            int s = 0;
            for (int i = 0; i < m; i++) {
                s += cnt(~(stu[i] ^ men[p[i]]));
            }
            ans = max(ans, s);
        } while (next_permutation(p.begin(), p.end()));
        return ans;
    }
};
