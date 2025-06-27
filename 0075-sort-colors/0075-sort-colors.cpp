class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l = 0, r = nums.size()-1;
        int mid = 0;
        while(mid<=r){
            if(nums[mid]==2){
                swap(nums[mid],nums[r--]);
            } else if(nums[mid]==0){
                swap(nums[mid++],nums[l++]);
            } else {
                mid++;
            }
        }
    }
};