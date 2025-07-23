class Solution {
public:
    int longestValidParentheses(string s) {
        int close = 0, open = 0, ans = 0;

        for(char ch : s){
            if(ch == '(') open++;
            else close++;
            
            if(open == close) ans = max(ans,2*open);
            else if(close > open) open = close = 0;
        }

        open = close = 0;

        for(int i=s.length()-1;i>=0;i--){
            if(s[i] == '(') open++;
            else close++;
            
            if(open == close) ans = max(ans,2*open);
            else if(close < open) open = close = 0;
        }

        return ans;
    }
};