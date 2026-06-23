class Solution {
public:
    int mod=1e9+7;
    typedef long long ll;
    int N;
    int M;
    int t[2001][2001][2];
    ll solve(int i,int prevVal,bool increase,int m,int n){

        if(i==n){
            return 1;
        }

        ll result=0;

        if(t[i][prevVal][increase]!=-1){
            return t[i][prevVal][increase];
        }
        //increasing
        if(increase==true){

            for(int nextval=prevVal+1;nextval<=m;nextval++){
                result= (result+solve(i+1,nextval,false,m,n))%mod;
            }
        }else{
            //decreasing

            for(int nxtval=1;nxtval<prevVal;nxtval++){
                result= (result+solve(i+1,nxtval,true,m,n))%mod;
            }
        }

        return t[i][prevVal][increase]= result%mod;
    }
    int zigZagArrays(int n, int l, int r) {

        ll dp[2001][2001][2];
        // memset(dp,0,sizeof(dp));
        ll m=r-l+1;

        ll result=0;

        // for(int st=1;st<=m;st++){



        //     //increasing
        //     result=(result+solve(1,st,true,m,n))%mod;
        //     //decreasing
        //     result=( result+solve(1,st,false,m,n))%mod; 
        // }

        // return result;

        // bottom up


        for(int i=1;i<=m;i++){
            dp[n][i][1]=1;
            dp[n][i][0]=1;
        }


        for(int i=n-1;i>=0;i--){ //index

            vector<ll>cumsum1(m+1,0);
            vector<ll>cumsum0(m+1,0);

            for(int val=1;val<=m;val++){
                cumsum1[val]=(cumsum1[val-1]+dp[i+1][val][1])%mod;
                cumsum0[val]=(cumsum0[val-1]+dp[i+1][val][0])%mod;
            }

            for(int prev=1;prev<=m;prev++){ //previous
                // for(int nextval=prev+1;nextval<=m;nextval++){ //increasing
                //     dp[i][prev][1]=(dp[i][prev][1] +dp[i+1][nextval][0])%mod;
                    
                // }

                dp[i][prev][1]=(cumsum0[m]-cumsum0[prev]+mod)%mod;


                // for(int nxtval=1;nxtval<prev;nxtval++){ //decreasing
                //         dp[i][prev][0]=(dp[i][prev][0] +dp[i+1][nxtval][1])%mod;
                //     }
                     dp[i][prev][0]=(cumsum1[prev-1]);

            }
        }

        for(int st=1;st<=m;st++){
            result=(result+dp[1][st][1]) %mod;
             result=(result+dp[1][st][0]) %mod;
        }

        return result;


        
        
    }
};