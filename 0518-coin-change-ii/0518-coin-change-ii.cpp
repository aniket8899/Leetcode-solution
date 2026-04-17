class Solution {
public:
    int solve(int amount,vector<int>& coins, vector<vector<int>>&dp,int i){
        // base case
        if(i==0){
            return (amount%coins[0]==0);
        }

        if(dp[i][amount]!=-1){
            return dp[i][amount];
        }


        // include
        int include=0;

        if(coins[i]<=amount){
            include=solve(amount-coins[i],coins,dp,i);
        }

        // exclude
        int exclude=solve(amount,coins,dp,i-1);

        return dp[i][amount]=include+exclude;
    }
    int change(int amount, vector<int>& coins) {

        int n=coins.size();
       vector<vector<int>>dp(n,vector<int>(amount+1,-1));

        return solve(amount,coins,dp,n-1);
        
        
    }
};