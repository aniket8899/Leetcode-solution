class Solution {
public:
const int mod=1e9+7;
    int numSub(string s) {

        int n=s.size();
        int sum=0;
        int cnt=0;

        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                cnt++;
            }else{
                cnt=0;
                
            }
            sum=(sum+cnt)%mod;
        }
        return sum;
        
    }
};