// Write an efficient algorithm that searches for a value in an m x n matrix.
// This matrix has the following properties:

//   Integers in each row are sorted from left to right.
//   The first integer of each row is greater than the last integer of the
//   previous row.

// time complexity o(logn + logm) = o(log(mn))
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // find the first row where it's first element is less or equal than target
        auto itr = lower_bound(matrix.begin(), matrix.end(), target, [](auto v, auto t){ return v[0] <= t; });
        // we have to take a step back since lower_bound returns iterator points to 
        // the first element where cmp(element, value) evaluate to false 
        itr = itr == matrix.begin() ? itr : itr - 1;
        auto itc = lower_bound((*itr).begin(), (*itr).end(), target);
        return itc != (*itr).end() ? *itc == target : false;
    }
};

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l = 0, r = matrix.size();
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (matrix[mid][0] <= target) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        l = max(0, l - 1);
        int b = 0, e = matrix[l].size();
        while (b < e) {
            int mid = b + (e - b) / 2;
            if (matrix[l][mid] < target) {
                b = mid + 1;
            } else {
                e = mid;
            }
        }
        return b == matrix[l].size() ? false : matrix[l][b] == target;
    }
};
