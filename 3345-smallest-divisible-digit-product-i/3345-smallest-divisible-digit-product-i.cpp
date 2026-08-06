class Solution {
public:
    int solve(int n){

        int prod=1;


        while(n!=0){
            int rem=n%10;

            prod=prod*rem;

            n/=10;
        }

        return prod;
    }
    int smallestNumber(int n, int t) {

        int mini=INT_MAX;
        int prod=1;

        // if(n==1 && t==1) return 1;

        if(n<=t) return t;

        

        // if(n==1 && t==2) return 2;

       for(int i=n;i<=100;i++){
         int ans=solve(i);

         if(ans%t==0){
            mini=min(mini,i);
         }
       }

       return mini;
        
    }
};