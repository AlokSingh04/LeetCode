class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();

        for(int i=0;i<n;i++){
            sum += nums[i];
        }
        if(sum%2!=0) return 0;

        int W = sum/2;
        vector<vector<unsigned long long>> dp(n+1,vector<unsigned long long>(W+1,0));
        dp[0][0] = 1;

        for(int i=1;i<=n;i++){
            for(int j=0;j<=W;j++){
                if(nums[i-1] > j) dp[i][j] = dp[i-1][j];
                else dp[i][j] = dp[i-1][j] + dp[i-1][j-nums[i-1]];
            }
        }

        return dp[n][W] != 0;
    }
};