// You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).
//
// You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n / 2; i++) {
            int k = n - 2 * i;
            for (int j = 0; j < k - 1; j++) {
                int t1 = matrix[i][i + j], t2 = matrix[i + j][i + k - 1];
                int t3 = matrix[i + k - 1][i + k - j - 1], t4 = matrix[i + k - j - 1][i];
                matrix[i][i + j] = t4;
                matrix[i + j][i + k - 1] = t1;
                matrix[i + k - 1][i + k - j - 1] = t2;
                matrix[i + k - j - 1][i] = t3;
            }
        }
    }
};

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n / 2; i++) {
            int k = n - 2 * i;
            for (int j = 0; j < k - 1; j++) {
                swap(matrix[i][i + j], matrix[i + j][i + k - 1]);
                swap(matrix[i][i + j], matrix[i + k - j - 1][i]);
                swap(matrix[i + k - j - 1][i], matrix[i + k - 1][i + k - j - 1]);
            }
        }
    }
};


/*
 * clockwise rotate
 * first reverse up to down, then swap the symmetry 
 * 1 2 3     7 8 9     7 4 1
 * 4 5 6  => 4 5 6  => 8 5 2
 * 7 8 9     1 2 3     9 6 3
 */
void rotate(vector<vector<int> > &matrix) {
    reverse(matrix.begin(), matrix.end());
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = i + 1; j < matrix[i].size(); ++j) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
}
