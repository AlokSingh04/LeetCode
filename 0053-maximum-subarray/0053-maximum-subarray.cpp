class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int temp = nums[0];
        int sum = nums[0];

        for(int i=1; i<nums.size(); i++){
            if(temp+nums[i] < nums[i]){
                temp = nums[i];
            } else {
                temp += nums[i];
            }
            sum = max(sum, temp);
        }

        return sum;
    }
};