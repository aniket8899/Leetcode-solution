class Solution {
public:
    int reverse(int n){
        int sum=0;

        while(n!=0){
            int rem=n%10;
            sum=sum*10+rem;

            n/=10;

        }

        return sum;
    }

   bool isprime(int n){
    if(n<=1) return false;


    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            return false;
        }
    }
    return true;
   }

    int sumOfPrimesInRange(int n) {

        int store=n;
        int reverseans=reverse(n);
        int mini=min(store,reverseans);

        int maxi=max(store,reverseans);

        int totalsum=0;

        //find prime
        for(int i=mini;i<=maxi;i++){
           if(isprime(i)){
            totalsum+=i;

           }
        }

        return totalsum;


        
    }
};