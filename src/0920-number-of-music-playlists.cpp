// Your music player contains n different songs and she wants to listen to goal
// (not necessarily different) songs during your trip.  You create a playlist
// so that:
//
// Every song is played at least once
// A song can only be played again only if k other songs have been played
// Return the number of possible playlists.  As the answer can be very large,
// return it modulo 10^9 + 7.

class Solution {
public:
    int numMusicPlaylists(int n, int goal, int k) {
        const long long mod = 1'000'000'007;
        vector<vector<long long>> dp(goal + 1, vector<long long>(n + 1, 0));
        // init case, fill 0 slot with 0 song
        dp[0][0] = 1;
        for (int i = 1; i <= goal; i++) {
            for (int j = 1; j <= n; j++) {
                // if the ith song is a new song compare to solution
                // dp[i-1][j-1], there is (N - j + 1) choices
                dp[i][j] = dp[i-1][j-1] % mod * (n - j + 1) % mod;
                if (j > k) {
                    // otherwise #choices is (j-k) if j > k else 0
                    dp[i][j] = (dp[i][j] + dp[i-1][j] % mod * (j - k) % mod) % mod;
                }
            }
        }
        return dp[goal][n] % mod;
    }
};
