// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

// standard binary search
class Solution {
public:
    int firstBadVersion(int n) {
        int l = 1, r = n, mid;
        while (l < r) {
            mid = l + (r - l) / 2;
            if (!isBadVersion(mid)) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return l;
    }
};
