class Solution {
public:
    int maxScore(vector<vector<int>>& dp, vector<int>& nums, int total, int i, int j){
        if(i>j) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        dp[i][j] = total - min(maxScore(dp,nums,total-nums[i],i+1,j), maxScore(dp,nums,total-nums[j],i,j-1));

        return dp[i][j];
    }

    bool predictTheWinner(vector<int>& nums) {
        vector<vector<int>> dp(21, vector<int>(21,-1));

        int total=0;
        for(int x : nums) total += x;

        int res = maxScore(dp,nums,total,0,nums.size()-1);

        return res >= total-res; 
    }
};