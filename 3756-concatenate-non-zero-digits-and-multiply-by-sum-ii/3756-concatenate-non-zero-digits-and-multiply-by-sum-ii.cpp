class Solution {
public:
    typedef long long ll;
    int mod=1e9+7;
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {

        // first we find a prefix sum

        int n=s.size();
        vector<int>digitsum(n,0);

        digitsum[0]=s[0]-'0';


        for(int i=1;i<n;i++){
            digitsum[i]=digitsum[i-1]+s[i]-'0';
        }

        vector<int>numbersupto(n,0);
        ll sum=0;

        for(int i=0;i<n;i++){
            if(s[i]!='0'){
                sum=(sum*10+s[i]-'0')%mod;
                numbersupto[i]=sum;
            }else{
                numbersupto[i]=sum;
            }
        }

        vector<int>nonzerodigit(n,0);

        if(s[0]!='0'){
            nonzerodigit[0]=1;
        }else{
             nonzerodigit[0]=0;
        }
        

       for(int i=1;i<n;i++){
        if(s[i]!='0'){
            nonzerodigit[i]=nonzerodigit[i-1]+1;
        }else{
            nonzerodigit[i]=nonzerodigit[i-1];
        }
       }

        vector<ll> pow10(n+1,1);
        for(int i=1;i<=n;i++){
         pow10[i]=(pow10[i-1]*10)%mod;
        }

        int m=queries.size();
        
        vector<int>result(m);

        for(int i=0;i<m;i++){
            int l=queries[i][0];
            int r=queries[i][1];

            ll sum;

            //  sum*x
            if(l>0){
             sum=(digitsum[r]-digitsum[l-1]+mod)%mod;
            }else{
                sum=digitsum[r]%mod;
            }
            int numberbefore= (l==0) ? 0 : numbersupto[l-1];

            int k=nonzerodigit[r]- ((l==0) ? 0:nonzerodigit[l-1]);

            ll x=(numbersupto[r]-(numberbefore*pow10[k] %mod)+mod)%mod;


            result[i]=(int)((sum*x)%mod);


        }

        return result;



        
    }
};