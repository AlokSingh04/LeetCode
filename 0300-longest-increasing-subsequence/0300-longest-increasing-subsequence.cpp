class Solution {
public:
    int func(vector<int>& dp, int idx, vector<int>& nums){
        if(dp[idx] != -1) return dp[idx];
        int maxlength = 1;
        for(int i=idx-1; i>=0; i--){
            if(nums[i]<nums[idx]){
                int length = 1 + func(dp, i, nums);
                maxlength = max(maxlength, length);
            }
        }

        return dp[idx] = maxlength;
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,-1);
        int ans = 0;
        for(int i=0;i<n;i++){
            ans = max(ans, func(dp,i,nums));
        }

        return ans;
    }
};