class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int count = 0, count1 = 0;
        int cand = 0, cand1=0;

        for(int x : nums){
            if(cand1 == x) count1++;
            else if(cand == x) count++;
            else if(count==0){
                count++;
                cand = x;
            } 
            else if(count1==0){
                count1++;
                cand1 = x;
            } 
            else{
                count--;
                count1--;
            }
        }

        count=0, count1=0;
        for(int x : nums){
            if(cand == x) count++;
            else if(cand1 == x) count1++;
        }

        vector<int> res;
        if(count > double(nums.size())/3.0) res.push_back(cand);
        if(count1 > double(nums.size())/3.0) res.push_back(cand1);

        return res;
    }
};