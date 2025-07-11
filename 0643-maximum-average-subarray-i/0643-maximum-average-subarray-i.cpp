class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int temp = 0;
        for(int i=0;i<k;i++){
            temp+=nums[i];
        }

        int sum = temp;
        for(int i=k;i<nums.size();i++){
            temp += nums[i] - nums[i-k];
            sum = temp > sum ? temp : sum;
        }

        return double(sum)/k;
    }
};