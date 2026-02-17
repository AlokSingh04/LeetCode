class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        int penalty = 0;
        for(int i=0;i<n;i++){
            if(customers[i] == 'Y') penalty++;
        }
        int ans_index = -1;
        int mn = penalty;
        for(int i=0;i<n;i++){
            if(customers[i] == 'Y') penalty--;
            else penalty++;
            
            if(mn > penalty){
                mn = penalty;
                ans_index = i;
            }
            cout<<ans_index<<" ";
        }

        return ans_index+1;
    }
};