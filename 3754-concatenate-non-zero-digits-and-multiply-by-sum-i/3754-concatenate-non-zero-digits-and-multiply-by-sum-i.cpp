class Solution {
public:
    long long sumAndMultiply(int n) {
        long long sum=0;
        long long sum1=0;
        while(n>0)
        {
            long long rem=n%10;
            if(rem!=0)
            {
               sum=sum*10+rem;
               sum1+=rem;
             
            }
             n/=10;
          
        }
        long long ans=0;
        while(sum>0)
        {
            long long digit=sum%10;
            ans=ans*10+digit;
            sum/=10;
        }

        return ans*sum1;
    }
};