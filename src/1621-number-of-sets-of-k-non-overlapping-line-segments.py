# Given n points on a 1-D plane, where the ith point (from 0 to n-1) is at x =
# i, find the number of ways we can draw exactly k non-overlapping line
# segments such that each segment covers two or more points. The endpoints of
# each segment must have integral coordinates. The k line segments do not
# have to cover all n points, and they are allowed to share endpoints.

# Return the number of ways we can draw k non-overlapping line segments. Since
# this number can be huge, return it modulo 10^9 + 7.

class Solution:
    def numberOfSets(self, n: int, k: int) -> int:
        res = 1
        for i in range(1, 2 * k + 1):
            res *= (n + k - i)
            res //= i
        return res % 1000000007
