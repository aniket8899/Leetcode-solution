class Solution {
public:

    // 0-999=0
    // 1000-999,999=1(998,999)
    // 1,000,000-999,999,9999





    long long countCommas(long long n) {
        if(n<1000) return 0;
        long long temp=1000;
        long long ans=0;

        while(temp<=n){
           long long diff=n-temp+1;
            ans+=diff;
            temp*=1000;
        }
        return ans;
       
    }
};