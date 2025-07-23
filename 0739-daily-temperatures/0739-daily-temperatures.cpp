class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& nums) {
        vector<int> res(nums.size(),0);
        stack<int> st;

        for(int i=0;i<nums.size();i++){
            while(!st.empty() && nums[i] > nums[st.top()]){
                int temp = st.top();
                st.pop();
                res[temp] = i-temp;
            }
            st.push(i);
        }

        return res;
    }
};