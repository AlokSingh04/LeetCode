class Solution {
public:
    void func(vector<int>& nums, vector<vector<int>>& res, vector<int> temp, int i){
        if(i == nums.size()){
            res.push_back(temp);
            return;
        }

        // exclude.
        func(nums, res, temp, i+1);

        // include.
        temp.push_back(nums[i]);
        func(nums, res, temp, i+1);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        func(nums,res,temp,0);

        return res;    
    }
};