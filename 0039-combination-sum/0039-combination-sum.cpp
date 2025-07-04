class Solution {
public:
    void backtrack(vector<int>& nums, vector<vector<int>>& res, int target, vector<int> temp, int sum, int start){
        if(sum == target){
            res.push_back(temp);
            return;
        }

        for(int i=start;i<nums.size();i++){
            if(sum+nums[i] <= target){
                temp.push_back(nums[i]);
                backtrack(nums,res,target,temp,sum+nums[i],i);
                temp.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> temp;

        backtrack(candidates,res,target,temp,0,0);

        return res;
    }
};