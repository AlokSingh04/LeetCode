class Solution {
public:
    bool isPrime(int n){
        if(n<=1) return 0;

        for(int i=2; i*i<=n; i++) if(n%i == 0) return 0;

        return 1;
    }

    int maximumPrimeDifference(vector<int>& nums) {
        int i=0, j=nums.size()-1;

        for(i=0;i<nums.size();i++) if(isPrime(nums[i])) break;
        for(j=nums.size()-1;j>=0;j--) if(isPrime(nums[j])) break;
        
        return j-i;
    }
};