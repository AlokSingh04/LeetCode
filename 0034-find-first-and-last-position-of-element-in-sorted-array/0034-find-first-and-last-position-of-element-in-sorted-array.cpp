class Solution {
public:
    int firstOccurance(vector<int> nums, int target){
        int ans = -1;
        int l = 0;
        int r = nums.size()-1;

        while(l <= r){
            int mid = (l+r)/2;

            if(nums[mid] == target){
                ans = mid;
                r = mid-1;
            } else if(nums[mid] > target){
                r = mid-1;
            } else {
                l = mid + 1;
            }
        }

        return ans;
    }

    int secondOccurance(vector<int> nums, int target){
        int ans = -1;
        int l = 0;
        int r = nums.size()-1;

        while(l <= r){
            int mid = (l+r)/2;

            if(nums[mid] == target){
                ans = mid;
                l = mid+1;
            } else if(nums[mid] > target){
                r = mid-1;
            } else {
                l = mid + 1;
            }
        }

        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res;

        res.push_back(firstOccurance(nums,target));
        res.push_back(secondOccurance(nums,target));

        return res;
    }
};