// There is a long and thin painting that can be represented by a number line. The painting was painted with multiple overlapping segments where each segment was painted with a unique color. You are given a 2D integer array segments, where segments[i] = [starti, endi, colori] represents the half-closed segment [starti, endi) with colori as the color.
//
// The colors in the overlapping segments of the painting were mixed when it was painted. When two or more colors mix, they form a new color that can be represented as a set of mixed colors.
//
// For example, if colors 2, 4, and 6 are mixed, then the resulting mixed color is {2,4,6}.
// For the sake of simplicity, you should only output the sum of the elements in the set rather than the full set.
//
// You want to describe the painting with the minimum number of non-overlapping half-closed segments of these mixed colors. These segments can be represented by the 2D array painting where painting[j] = [leftj, rightj, mixj] describes a half-closed segment [leftj, rightj) with the mixed color sum of mixj.
//
// For example, the painting created with segments = [[1,4,5],[1,7,7]] can be described by painting = [[1,4,12],[4,7,7]] because:
// [1,4) is colored {5,7} (with a sum of 12) from both the first and second segments.
// [4,7) is colored {7} from only the second segment.
// Return the 2D array painting describing the finished painting (excluding any parts that are not painted). You may return the segments in any order.
//
// A half-closed segment [a, b) is the section of the number line between points a and b including point a and not including point b.
//

class Solution {
public:
    vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {
        vector<pair<int, int>> split;
        for (const auto &vec : segments) {
            split.emplace_back(vec[0], vec[2]);
            split.emplace_back(vec[1], -vec[2]);
        }
        // sort "change"
        sort(split.begin(), split.end());
        vector<vector<long long>> ans;
        long long first = -1, mixed = 0;
        for (const auto &[last, color] : split) {
            if (first != -1 && first != last && mixed != 0) {
                ans.push_back({first, last, mixed});
            }
            first = last;
            mixed += color;
        }
        return ans;
    }
};
// priority queue version:

class Solution {
public:
    vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (const auto &vec : segments) {
            pq.emplace(vec[0], vec[2]);
            pq.emplace(vec[1], -vec[2]);
        }
        long long first = -1, color = 0;
        vector<vector<long long>> ans;
        while (!pq.empty()) {
            auto [pos, dc] = pq.top();
            pq.pop();
            if (first != -1 && first != pos && color != 0) {
                // when color equals zero, this means we have a gap between segments
                // when ever change happens, we save the last segment
                ans.push_back({first, pos, color});
            }
            // update color and pos, we should always update pos and color 
            color += dc;
            first = pos;
        }
        return ans;
    }
};
