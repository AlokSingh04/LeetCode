class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        vector<int> N(bank.size());

        for(int i=0; i<bank.size(); i++){
            N[i] = count(bank[i].begin(),bank[i].end(),'1');
        }

        int ans = 0, temp = 0;
        for(int i : N){
            if(i!=0 && temp==0){
                temp = i;
            } else if(i!=0) {
                ans += temp*i;
                temp = i;
            }
        }

        return ans;
    }
};