class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int maxProfit=0,cheap=arr[0];
        for(int i=0;i<arr.size();i++){
            if(cheap>arr[i]){
                cheap=arr[i];
            } else if(maxProfit<arr[i]-cheap){
                maxProfit=arr[i]-cheap;
            }
        }
        return maxProfit;
    }
};