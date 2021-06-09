// You are given a large sample of integers in the range [0, 255]. Since the
// sample is so large, it is represented by an array count where count[k] is
// the number of times that k appears in the sample.
//
// Calculate the following statistics:
//
// minimum: The minimum element in the sample.
// maximum: The maximum element in the sample.
// mean: The average of the sample, calculated as the total sum of all
// elements divided by the total number of elements.
// median:
// If the sample has an odd number of elements, then the median is the
// middle element once the sample is sorted.
// If the sample has an even number of elements, then the median is the
// average of the two middle elements once the sample is sorted.
// mode: The number that appears the most in the sample. It is guaranteed to
// be unique.
// Return the statistics of the sample as an array of floating-point
// numbers [minimum, maximum, mean, median, mode]. Answers within 10^-5 of the
// actual answer will be accepted.

class Solution {
public:
    vector<double> sampleStats(vector<int>& count) {
        using int64 = long long;
        int total = accumulate(count.begin(), count.end(), 0);
        int idx1 = total / 2, idx2 = (total - 1) / 2;
        double v1 = 0, v2 = 0;
        int64 sum = 0;
        double minv = INT_MAX, maxv = INT_MIN;
        int curridx = 0;
        int maxc = 0;
        double mode = 0;
        for (int i = 0; i < count.size(); i++) {
            sum += (int64)i * count[i];
            if (count[i] > 0) {
                minv = min(minv, (double)i);
                maxv = max(maxv, (double)i);
            }
            if (curridx <= idx1 && idx1 < curridx + count[i]) {
                v1 = i;
            }
            if (curridx <= idx2 && idx2 < curridx + count[i]) {
                v2 = i;
            }
            if (maxc < count[i]) {
                mode = i;
                maxc = count[i];
            }
            curridx += count[i];
        }
        return {minv, maxv, 1.0 * sum / total, (v1 + v2) / 2, mode};

    }
};
