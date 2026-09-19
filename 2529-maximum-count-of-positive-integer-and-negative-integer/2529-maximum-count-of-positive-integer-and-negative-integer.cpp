class Solution {
public:
    int maximumCount(vector<int>& nums) {
        if(nums[0]==0 && nums[nums.size()-1]==0) return 0;

        int res=nums.size()-1;
        int l=0, r=nums.size()-1;
        while(l<=r){
            int mid = (l+r)/2;
            
            if(nums[mid]<=0) l = mid+1;
            else{
                res = mid;
                r = mid-1;
            }
        }

        int res1=0;
        l=0, r=nums.size()-1;
        while(l<=r){
            int mid = (l+r)/2;
            
            if(nums[mid]>=0) r = mid-1;
            else{
                res1 = mid;
                l = mid+1;
            }
        }

        return max(res1, int(nums.size())-1-res)+1;
    }
};