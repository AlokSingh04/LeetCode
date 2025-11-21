class Solution {
public:
    int func(vector<vector<int>>& dp, vector<int>& piles, int total, int i, int j){
        if(i>j) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        dp[i][j] = total-min(func(dp,piles,total-piles[i],i+1,j), func(dp,piles,total-piles[j],i,j-1));

        return dp[i][j];
    }

    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n, vector<int>(n,-1));

        int total = 0;
        for(int x : piles) total += x;

        int res = func(dp,piles,total,0,piles.size()-1);

        return res > total-res;
    }
};