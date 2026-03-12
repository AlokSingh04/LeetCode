class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> count;
        int n = nums.size();
        for(int num : nums){
            count[num]++;
        }
        
        vector<pair<int,int>> arr;
        for(const auto i : count){
            arr.push_back({i.second, i.first});
        }

        sort(arr.rbegin(), arr.rend());

        vector<int> ans;
        for(int i=0;i<k;i++){
            ans.push_back(arr[i].second);
        }

        return ans;
    }
};