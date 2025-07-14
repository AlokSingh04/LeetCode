class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        vector<int> ans(nums.size());
        ans[0] = nums[0];
        ans[1] = max(nums[0],nums[1]);
        for(int i=2;i<ans.size()-1;i++){
            ans[i] = max(ans[i-1],ans[i-2]+nums[i]);
        }

        if(nums.size()==2) return ans[1];
        vector<int> ans2(nums.size());
        ans2[1] = nums[1];
        ans2[2] = max(nums[1],nums[2]);
        for(int i=3;i<ans2.size();i++){
            ans2[i] = max(ans2[i-1],ans2[i-2]+nums[i]);
        }

        return max(ans[nums.size()-2],ans2[nums.size()-1]);
    }
};