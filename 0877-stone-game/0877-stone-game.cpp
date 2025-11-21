class Solution {
public:
    int solve(vector<vector<int>>& dp, vector<int>& piles, int i, int j) {
        if (i > j) return 0;

        if (dp[i][j] != -1) return dp[i][j];

        int left  = piles[i] - solve(dp, piles, i + 1, j);
        int right = piles[j] - solve(dp, piles, i, j - 1);

        return dp[i][j] = max(left, right);
    }

    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));

        return solve(dp, piles, 0, n - 1) > 0;
    }
};
