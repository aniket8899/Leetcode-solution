class Solution {
public:
 const int mod=1e9+7;

    long long solve(long long a,long long b){
        long long ans=1;

        while(b>0){
            if(b%2==1){
                ans=(ans*a)%mod;
            }

            a=(a*a)%mod;
            b=b/2;
        }

        return ans%mod;
    }
    int sumDecoded(vector<long long>& nums) {
        
        long long sum=0;

        for(int i=0;i<nums.size();i++){
        long long width=nums[i]%10;

        long long d=nums[i]/10;

        string s=to_string(d);

        long long x=(stoi(s.substr(0,width)))%mod;

        long long y=(stoi(s.substr(width)))%mod;

         sum+=solve(x,y);



        }

        return sum%mod;

    }
};