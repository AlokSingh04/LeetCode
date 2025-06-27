class Solution {
public:
    int distinctAverages(vector<int>& nums) {
        sort(nums.begin(),nums.end());

        unordered_map<double,int> store;
        int l=0,r=nums.size()-1;
        while(l<r){
            store[(double(nums[l]+nums[r]))/2]++;
            l++;
            r--;
        }

        int count=0;
        for(auto& pair : store){
            count++;
        }

        return count;
    }
};