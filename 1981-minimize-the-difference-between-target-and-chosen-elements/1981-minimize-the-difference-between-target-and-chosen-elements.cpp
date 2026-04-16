class Solution {
public:
    int solve(vector<vector<int>>& mat, int target,int totalsum,int row, vector<vector<int>>&dp){
        int n=mat.size();
        // base case
        if(row==mat.size()){
            return abs(totalsum-target);
        }

        if(dp[row][totalsum]!=-1){
            return dp[row][totalsum];
        }
        // 1 case
        int ans=INT_MAX;

        for(int col=0;col<mat[row].size();col++){
            int recans=solve(mat,target,totalsum+mat[row][col],row+1,dp);

            ans=min(ans,recans);
        }
        return dp[row][totalsum]= ans;
    }
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        int n=mat.size();
        
        int totalsum=0;
        int row=0;

        vector<vector<int>>dp(n + 1, vector<int>(5001, -1));

        return solve(mat,target,totalsum,row,dp);
    }
};