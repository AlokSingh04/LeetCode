class Solution {
public:
    int mySqrt(int x) {
        long left = 1;
        long right = x/1;
        int ans=0;

        while(left <= right){
            long mid = (left + right) / 2;

            if((long)mid * mid == x) return mid;
            
            if((long)mid * mid < x){
                ans = mid;
                left = mid+1;
            } else {
                right = mid-1;
            }
        }

        return ans;
    }
};