class Solution {
public:
    int numDays(vector<int>& weights, int cap){
        int i=0,days=0;
        int sum=0;
        while(i<weights.size()){
            if(sum + weights[i] <= cap){
                sum+=weights[i];
                i++;
            } else {
                days++;
                sum=0;
            }
        }
        
        return ++days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int r = 0;
        int l = 1;
        for(int i=0;i<weights.size();i++){
            r+=weights[i];
            if(weights[i]>l){
                l=weights[i];
            }
        }

        int res=-1;

        while(l<=r){
            int mid = (l+r)/2;
            
            if(numDays(weights,mid) > days){
                l = mid+1;
            } else {
                res = mid;
                r = mid-1;
            }
        }

        return res;
    }
};