class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();

        vector<vector<int>> dp(n+1,vector<int>(m+2,INT_MAX));
        for(int i=1;i<=m;i++){
            dp[0][i] = 0;
        }

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                dp[i][j] = min(dp[i-1][j-1],min(dp[i-1][j],dp[i-1][j+1])) + matrix[i-1][j-1];
            }
        }

        int min_sum = INT_MAX;
        for(int i=1;i<=m;i++){
            if(dp[n][i] < min_sum) min_sum = dp[n][i];
        }

        return min_sum;
    }
};