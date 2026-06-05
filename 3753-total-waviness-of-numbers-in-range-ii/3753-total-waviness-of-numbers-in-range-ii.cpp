class Solution {
public:
    typedef long long ll;
    string s;
    int n;
    pair<ll,ll>dp[20][11][11][2];
    bool vis[20][11][11][2];


    pair<ll,ll>solve(int curr,int prev,int prevprev, bool islimitedwithactualnumber,bool isleadingzero){
        if(curr==n){
            return {1,0};
        }

        if(!islimitedwithactualnumber && vis[curr][prev+1][prevprev+1][isleadingzero]){
            return dp[curr][prev+1][prevprev+1][isleadingzero];
        }

        ll totalnumber=0;
        ll totalwavescore=0;

        int limitdigit=islimitedwithactualnumber ? (s[curr]-'0') :9; 

        for(int digit=0;digit<=limitdigit;digit++){
            bool newisleadingzero=isleadingzero && (digit==0); // leading zero check kar rha h ki abhi tak zero aa rha h kya
            int newprevprev=prev; // ham jab curr digit ko aaga badhayenga to prevprev ko bhi update karenga n
            int newprev=newisleadingzero ?-1 :digit;// prev ko bhi

            auto [remaintotalnumber,remaintotalwavescore]=solve(curr+1,newprev,newprevprev,islimitedwithactualnumber && (digit==limitdigit),newisleadingzero);

            if(!newisleadingzero && prevprev>=0 &&prev>=0){

                bool peak= (prevprev< prev && prev>digit);
                bool valley= (prevprev >prev &&prev <digit);

                if(peak || valley){
                    totalwavescore+=remaintotalnumber;
                }
            }
            totalnumber+=remaintotalnumber;
            totalwavescore+=remaintotalwavescore;


        }
         if(!islimitedwithactualnumber){
            vis[curr][prev+1][prevprev+1][isleadingzero] = true;
            dp[curr][prev+1][prevprev+1][isleadingzero]
                = {totalnumber,totalwavescore};
        }
        return {totalnumber,totalwavescore};
    }
    ll func(ll num){
        if(num <100){
            return 0;
        }

        memset(vis,false,sizeof(vis));

        s=to_string(num);
        n=s.size();
        auto [totalnumber,totalwavescore]=solve(0,-1,-1,true,true);

        return totalwavescore;
    }
    long long totalWaviness(long long num1, long long num2) {

         return func(num2)-func(num1-1);
        
    }
};