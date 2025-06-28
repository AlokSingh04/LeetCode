class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int a,b;
        for(const string& str : tokens){
            if(str == "+"){
                a = st.top();
                st.pop();
                b = st.top();
                st.pop();
                st.push(b+a);
            } else if(str == "-"){
                a = st.top();
                st.pop();
                b = st.top();
                st.pop();
                st.push(b-a);
            } else if(str == "*"){
                a = st.top();
                st.pop();
                b = st.top();
                st.pop();
                st.push(b*a);
            } else if(str == "/"){
                a = st.top();
                st.pop();
                b = st.top();
                st.pop();
                st.push(b/a);
            } else {
                st.push(stoi(str));
            }
        }
        return st.top();
    }
};