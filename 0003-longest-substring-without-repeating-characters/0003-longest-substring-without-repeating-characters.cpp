class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<int> set;
        int res=0,l=0;
        
        for(int r=0; r<s.size(); r++){
            while(set.find(s[r]) != set.end()){
                set.erase(s[l]);
                
                l++;
            }
            set.insert(s[r]);
            res = max(res, r-l+1);
        }

        return res;
    }
};