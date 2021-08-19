// There are 8 prison cells in a row and each cell is either occupied or vacant.
//
// Each day, whether the cell is occupied or vacant changes according to the following rules:
//
// If a cell has two adjacent neighbors that are both occupied or both vacant, then the cell becomes occupied.
// Otherwise, it becomes vacant.
// Note that because the prison is a row, the first and the last cells in the row can't have two adjacent neighbors.
//
// You are given an integer array cells where cells[i] == 1 if the ith cell is occupied and cells[i] == 0 if the ith cell is vacant, and you are given an integer n.
//
// Return the state of the prison after n days (i.e., n such changes described above).
//

class Solution {
public:
    vector<int> next(vector<int> &cells) {
        vector<int> ans(1, 0);
        for (int i = 1; i < cells.size() - 1; i++) {
            ans.push_back(!(cells[i - 1] ^ cells[i + 1]));
        }
        ans.push_back(0);
        return ans;
    }

    bool equal(vector<int> &v1, vector<int> &v2) {
        for (int i = 0; i < v1.size(); i++) {
            if (v1[i] != v2[i]) {
                return false;
            }
        }
        return true;
    }

    int helper(vector<vector<int>> &s, vector<int> c) {
        for (int i = 0; i < s.size(); i++) {
            if (equal(s[i], c)) {
                return i;
            }
        }
        return -1;
    }

    void print(vector<int> &vec) {
        for (const auto i : vec) {
            cout << i << ' ';
        }
        cout << endl;
    }

    vector<int> prisonAfterNDays(vector<int>& cells, int n) {
        vector<vector<int>> states;
        states.push_back(cells);
        int k = -1;
        for (int i = 0; ;i++) {
            auto vec = next(states[i]);
            k = helper(states, vec);
            if (k != -1) {
                break;
            }
            states.push_back(vec);
        }
        return states[n > k ? (n - k) % (states.size() - k) + k : n];
    }
};
