class Solution {
private:
    void backtrack(int open_count,int close_count,int n,vector<string>& res,string stack){
        if(open_count == close_count && open_count == n){
            res.push_back(stack);
            return;
        }

        if(open_count < n){
            stack += '(';
            backtrack(open_count+1,close_count,n,res,stack);
            stack.pop_back();
        }

        if(close_count < open_count){
            stack += ')';
            backtrack(open_count,close_count+1,n,res,stack);
            stack.pop_back();
        }
    }

public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string stack;
        backtrack(0,0,n,res,stack);
        return res;
    }
};