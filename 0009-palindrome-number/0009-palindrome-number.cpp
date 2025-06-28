class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0){
            return 0;
        }
        long temp=0;
        for(int i=x;i!=0;i/=10){
            temp = temp*10 + (i%10);
        }
        
        return temp == x;
    }
};