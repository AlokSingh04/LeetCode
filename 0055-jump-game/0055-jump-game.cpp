class Solution {
public:
    bool canJump(vector<int>& nums) {
        int reach = nums.size()-1;
        for(int i=reach; i>=0; i--){
            if(nums[i]+i >= reach) reach=i;
        }

        if(reach == 0) return 1;
        return 0;
    }
};