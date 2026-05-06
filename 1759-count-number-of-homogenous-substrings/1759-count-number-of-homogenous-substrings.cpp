class Solution {
public:
// #define ll long long
 const int mod=1e9+7;
    int countHomogenous(string s) {
        int n=s.size();

        long long sum=0;
        
        
      long long r=0,l=0;

      while(r<n){
        if(s[r]==s[l]){
            sum+=(r-l+1)%mod;
        }else{
            sum=sum+1;
            l=r;

        }
        r++;
      }
      return sum%mod;
    }
};