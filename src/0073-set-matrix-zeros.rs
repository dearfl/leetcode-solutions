/*
Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

You must do it in place.
*/

// space O(m+n) solution
impl Solution {
    pub fn set_zeroes(matrix: &mut Vec<Vec<i32>>) {
        let n = matrix.len();
        let m = matrix.last().unwrap().len();
        let mut v0 = vec![0; m];
        let mut v1 = vec![0; n];
        for i in 0..n {
            for j in 0..m {
                if matrix[i][j] == 0 {
                    v0[j] = 1;
                    v1[i] = 1;
                }
            }
        }
        for i in 0..n {
            for j in 0..m {
                if v0[j] == 1 || v1[j] == 1 {
                    matrix[i][j] = 0;
                }
            }
        }
    }
}
