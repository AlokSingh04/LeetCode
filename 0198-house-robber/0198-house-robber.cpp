class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        
        vector<int> ans(nums.size());
        ans[0] = nums[0];
        ans[1] = max(nums[0],nums[1]);

        for(int i=2;i<ans.size();i++){
            ans[i] = max(ans[i-1],ans[i-2]+nums[i]);
        }

        return ans.back();
    }
};