class Solution {
public:
    const int mod=1e9+7;

int solve(int n){
    return n*(n+1)/2;
}

    int numSub(string s) {
        int cnt=0;
        int sum=0;

        for(int i=0;i<s.size();i++){
            if(s[i]=='1'){
                cnt++;
            }else{
                sum=(sum+solve(cnt))%mod;
                cnt=0;
            }
        }
        if(cnt){
            sum=(sum+solve(cnt))%mod;
        }

        return sum%mod;
        
    }
};