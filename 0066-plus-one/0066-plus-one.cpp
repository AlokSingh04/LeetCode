class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        int i = digits.size()-1;

        while(i>-1){
            int temp = digits[i]+carry;
            if(!(temp>9)){
                digits[i]+=carry;
                carry = temp/10;
                break;
            } else {
                cout<<temp%10<<" ";
                digits[i] = temp%10;
                carry = temp/10;
            }
            i--;
        }

        if(carry>0){
            digits.insert(digits.begin(),carry);
        }

        return digits;
    }
};