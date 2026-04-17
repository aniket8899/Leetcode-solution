class Solution {
public:
   int solve(vector<vector<int>>& grid, vector<vector<int>>&dp,int i,int j){
    // base case

    if(i==0 && j==0 ){
        return grid[0][0];
    }

    if(i<0 || j<0 ){
        return 1e9;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }

     // up
     int up=grid[i][j] + solve(grid,dp,i-1,j);

     // left
     int left=grid[i][j] +solve(grid,dp,i,j-1);

    return dp[i][j]=min(up,left);

   }
    int minPathSum(vector<vector<int>>& grid) {

        int n=grid.size();
        int m=grid[0].size();

        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));

        return solve(grid,dp,n-1,m-1);
        
    }
};