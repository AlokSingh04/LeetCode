class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0, sup;
        for(int i=0;i<nums.size();i++){
            if(count==0) sup = nums[i];

            if(sup!=nums[i]) count--;
            else count++;
        }

        return sup;
    }
};