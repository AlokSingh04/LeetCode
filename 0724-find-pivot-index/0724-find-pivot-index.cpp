class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }

        int left_sum = 0,right_sum = sum-nums[0];
        int index = 0;
        while(left_sum != right_sum){
            left_sum+=nums[index];
            index++;
            if(index == nums.size()){
                return -1;
            }
            right_sum-=nums[index];
        }
        
        return index;
    }
};