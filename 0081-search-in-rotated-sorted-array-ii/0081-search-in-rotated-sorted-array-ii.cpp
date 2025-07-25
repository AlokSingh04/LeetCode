class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l=0,r=nums.size()-1;
        while(l<=r){
            int mid = (l+r)/2;
            
            if(nums[mid] == target){
                return 1;
            }

            if(nums[mid]==nums[l] && nums[mid]==nums[r]){
                l++;
                r--;
                continue;
            }

            if(nums[mid] >= nums[l]){
                if(nums[l] <= target && nums[mid] >= target){
                    r = mid-1;
                } else {
                    l = mid+1;
                }
            } else {
                if(nums[mid] <= target && nums[r] >= target){
                    l = mid+1;
                } else {
                    r = mid-1;
                }
            }
        }
        return 0;
    }
};