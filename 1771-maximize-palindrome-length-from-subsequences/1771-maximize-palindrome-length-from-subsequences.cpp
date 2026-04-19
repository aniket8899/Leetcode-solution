class Solution {
public:
    int solve(string &s,int i,int j,vector<vector<int>>&dp){
        //base case

        if(i>j) return 0;

        if(i==j) return 1;

        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        if(s[i]==s[j]){
            return dp[i][j] =2+solve(s,i+1,j-1,dp);
        }

        int op1=solve(s,i+1,j,dp);
        int op2=solve(s,i,j-1,dp);

        return dp[i][j]=max(op1,op2);
    }
    int longestPalindrome(string word1, string word2) {
        string s=word1+word2;

        int n=s.size();

        vector<vector<int>>dp(n,vector<int>(n,-1));

        int len1=word1.size();
        int ans=0;

        for(int i=0;i<len1;i++){
            for(int j=len1;j<n;j++){
                if(s[i]==s[j]){
                    ans=max(ans,2+solve(s,i+1,j-1,dp));
                }
            }
        }
        return ans;

        
    }
};