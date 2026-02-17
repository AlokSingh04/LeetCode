class Solution {
public:
    vector<int> asteroidCollision(vector<int>& nums) {
        stack<int> st;
        int n = nums.size();

        for(int i=0;i<n;i++){
            if(nums[i] > 0){
                st.push(nums[i]);
                continue;
            }

            int p = -1*nums[i];
            while(!st.empty() && p > st.top() && st.top()>0){
                st.pop();
            }

            if(st.empty()) st.push(nums[i]);
            else if(st.top() == p) st.pop();
            else if(st.top() < 0) st.push(nums[i]);
        }

        vector<int> res;
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(),res.end());

        return res;
    }
};