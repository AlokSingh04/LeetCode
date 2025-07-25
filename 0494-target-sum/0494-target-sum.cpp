class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = 0;
        for(int i=0;i<n;i++){
            sum += nums[i];
        }
        if(abs(target) > sum || (target + sum) % 2 != 0) {
            return 0;
        }

        int W = (target+sum)/2;
        vector<vector<int>> dp(n+1,vector<int>(W+1,0));
        dp[0][0] = 1;

        for(int i=1;i<=n;i++){
            for(int j=0;j<=W;j++){
                if(nums[i-1] > j) dp[i][j] = dp[i-1][j];
                else dp[i][j] = dp[i-1][j] + dp[i-1][j-nums[i-1]];
            }
        }

        return dp[n][W];
    }
};