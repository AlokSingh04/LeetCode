class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        if(arr.size()<3){
            return 0;
        }
        
        int index = 0;
        while(index != arr.size()-2){
            if(arr[index] >= arr[index+1]){
                break;
            }
            index++;
        }
        while(index != arr.size()-1 && index > 0){
            if(arr[index] <= arr[index+1]){
                break;
            }
            index++;
        }

        return index == arr.size()-1;
    }
};