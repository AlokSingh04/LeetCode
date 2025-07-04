class Solution {
public:
    void backtrack(int open_count,int close_count,int n,vector<string>& res,string temp){
        if(close_count == n && open_count == n)  res.push_back(temp);

        if(open_count < n)  backtrack(open_count+1,close_count,n,res,temp+'(');

        if(close_count < open_count)  backtrack(open_count,close_count+1,n,res,temp+')');
    }

    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string temp;

        backtrack(0,0,n,res,temp);
        
        return res;
    }
};