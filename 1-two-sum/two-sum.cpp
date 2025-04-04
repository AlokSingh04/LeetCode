class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++){
            auto it = find(nums.begin(), nums.end(), target - nums[i]);
            if(it != nums.end() && (it - nums.begin() != i)){
                ans.push_back(i);
                ans.push_back(it - nums.begin());
                return ans;
            }  
        }
        return ans;

    }
};