class Solution {
public:
    // int countPrimes(int n) {
    //     if(n <= 1) return false;

    //     vector<bool> prime(n,true);
    //     prime[0] = prime[1] = false;

    //     for(int i=2; i*i<n; i++){
    //         if(prime[i]){
    //             for(int j=2*i; j<n; j+=i){
    //                 prime[j] = false;
    //             }
    //         }
    //     }

    //     return count(prime.begin(), prime.end(), true);
    // }



    int countPrimes(int n) {
        if(n<=2) return 0;
        vector<bool> arr(n+1,false);
        arr[2]=arr[3]=true;

        for(int x = 1; x*x<=n; x++){
            for(int y=1; y*y<=n; y++){
                int num = 4*x*x + y*y;
                if(num<=n && (num%12==1 || num%12==5)) arr[num] = !arr[num];
                num = 3*x*x + y*y;
                if(num<=n && num%12==7) arr[num] = !arr[num];
                num = 3*x*x - y*y;
                if(x>y && num<=n && num%12==11) arr[num] = !arr[num]; 
            }
        }

        for(int i = 5; i*i<=n; i++){
            if(!arr[i]) continue;
            for(int j=i*i; j<=n; j+=i*i) arr[j] = false;
        }

        return count(arr.begin()+2,arr.end(), true);
    }
};