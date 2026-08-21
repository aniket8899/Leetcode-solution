class Solution {
public:
    int solve(string &word1,string &word2,int i,int j,vector<vector<int>>&dp){
        int n=word1.size();
        int m=word2.size();

        if(i==n){
            return m-j;
        }

        if(j==m){
            return n-i;
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }

    int ans=0;

        if(word1[i]==word2[j]){
            ans=solve(word1,word2,i+1,j+1,dp);
        }else{
        int a=1+solve(word1,word2,i+1,j,dp);
        int b=1+solve(word1,word2,i,j+1,dp);
        int c=1+solve(word1,word2,i+1,j+1,dp);

        ans=min({a,b,c});

        }



        return  dp[i][j]= ans;

        
    }
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();

        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));

        int ans= solve(word1,word2,0,0,dp);

        return ans;
        
    }
};