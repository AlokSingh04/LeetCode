class Solution {
public:
    bool isPal(string& str,int l,int r){
        while(l<r){
            if(str[l]!=str[r]) return 0;
            l++;
            r--;
        }
        return 1;
    }

    void backtrack(string& str, vector<vector<string>>& res, vector<string>& temp, int start){
        if(start == str.length()){
            res.push_back(temp);
            return;
        }

        for(int i=start;i<str.length();i++){
            if(isPal(str,start,i)){
                temp.push_back(str.substr(start,i-start+1));
                backtrack(str,res,temp,i+1);
                temp.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string str) {
        vector<vector<string>> res;
        vector<string> temp;

        backtrack(str,res,temp,0);

        return res;
    }
};