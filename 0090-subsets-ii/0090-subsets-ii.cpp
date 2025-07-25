class Solution {
public:
    void func(vector<int>& nums, vector<vector<int>>& res, vector<int> temp, int start){
        res.push_back(temp);

        for(int i=start;i<nums.size();i++){
            if(i>start && nums[i] == nums[i-1]){
                continue;
            }
            temp.push_back(nums[i]);
            func(nums,res,temp,i+1);
            temp.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        sort(nums.begin(),nums.end());

        func(nums,res,temp,0);

        return res;
    }
};