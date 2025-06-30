class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> merged;

        for(vector<int>& temp : intervals){
            if(merged.empty() || merged.back()[1]<temp[0]){
                merged.push_back(temp);
            } else {
                merged.back()[1] = max(merged.back()[1],temp[1]);
            }
        }

        return merged;
    }
};