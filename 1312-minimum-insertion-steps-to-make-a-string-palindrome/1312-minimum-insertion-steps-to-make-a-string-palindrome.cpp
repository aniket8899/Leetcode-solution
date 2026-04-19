class Solution {
public:
    int solve(string &s,int st,int ed,vector<vector<int>>&dp){
        // base
        if(st>ed) return 0;

        if(st==ed) return 1;

        if(dp[st][ed]!=-1){
            return dp[st][ed];
        }
        // check
        if(s[st]==s[ed]){
            return dp[st][ed] =2+solve(s,st+1,ed-1,dp);
        }

        //2 option
        int op1=solve(s,st+1,ed,dp);
        int op2=solve(s,st,ed-1,dp);

        return dp[st][ed]=max(op1,op2);
    }
    int palindromesubsequence(string &s){

        int n=s.size();

        vector<vector<int>>dp(n,vector<int>(n,-1));

        return solve(s,0,n-1,dp);
    }
    int minInsertions(string s) {

        return s.size()- palindromesubsequence(s);
        
    }
};