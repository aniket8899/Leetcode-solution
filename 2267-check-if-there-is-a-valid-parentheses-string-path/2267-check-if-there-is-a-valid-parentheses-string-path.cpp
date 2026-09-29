class Solution {
public:
    bool solve(int i,int j,int ans,vector<vector<char>>&grid,vector<vector<vector<int>>>&dp){
        int n=grid.size();
        int m=grid[0].size();
        // 

        if(i>=n || j>=m){
            return false;
        }
       

        if(grid[i][j]=='('){
            ans++;
        }else{
            ans--;
        }

        if(ans<0){
            return false;
        }

         if(i==n-1 && j==m-1){
            return ans==0;
        }

        if(dp[i][j][ans]!=-1){
            return dp[i][j][ans];
        }



        bool down=solve(i+1,j,ans,grid,dp);
        bool right=solve(i,j+1,ans,grid,dp);

        return dp[i][j][ans]=(down || right);
    }
    bool hasValidPath(vector<vector<char>>& grid) {

        int n=grid.size();
        int m=grid[0].size();

        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(n+m+1,-1)));

        return solve(0,0,0,grid,dp);
        
    }
};