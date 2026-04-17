class Solution {
public:
 const int mod=1e9+7;

    int solve(int target,vector<vector<int>>& types,int i,  vector<vector<int>>&dp){
        // base case
      if(target==0){
        return 1;
      }


       if (i == 0) {
            int cnt = types[0][0];
            int marks = types[0][1];

            if (target % marks == 0 &&
                target / marks <= cnt) {
                return 1;
            }
            return 0;
        }

        if(dp[i][target]!=-1){
            return dp[i][target];
        }

        int ways=0;
        int cnt=types[i][0];
        int marks=types[i][1];

        for(int j=0;j<=cnt;j++){
            int temp=j*marks;

            if(temp<=target){
                ways=(ways+solve(target-temp,types,i-1,dp))%mod;
        }
        }
  
    return dp[i][target]=ways;
       

       
    }
    int waysToReachTarget(int target, vector<vector<int>>& types) {
        int n=types.size();
        
     vector<vector<int>>dp(n,vector<int>(target+1,-1));
   
     return solve(target,types,n-1,dp);

    }
};