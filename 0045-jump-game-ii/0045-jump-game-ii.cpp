class Solution {
public:
    int jump(vector<int>& nums) {
        int jump = 0;
        int maxreach = 0;
        int reach = 0;
        for(int i=0; i<nums.size()-1; i++){
            maxreach = max(maxreach, nums[i]+i);
            if(i == reach){
                jump++;
                reach = maxreach;
            }
        }

        return jump;
    }
};