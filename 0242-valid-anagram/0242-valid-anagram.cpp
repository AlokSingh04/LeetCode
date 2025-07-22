class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()){
            return 0;
        }

        unordered_map<char,int> map;
        for(char i : s){
            map[i]++;
        }

        for(char i : t){
            map[i]--;
            if(map[i] < 0) return 0;
        }

        return 1;
    }
};