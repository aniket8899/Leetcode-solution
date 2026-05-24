class Solution {
public:
    int solve(vector<int>& arr,int d,int i,vector<int>&dp){
        int n=arr.size();
        // base case
            if(i==n){
                return 0;
            }

            if(dp[i]!=-1){
                return dp[i];
            }

        //left (i-1,i-2....i-d)
        int ans=1;

        for(int j=i-1;j>=max(0,i-d);j--){
            if(arr[j]>=arr[i]) break;

            ans=max(ans,1+solve(arr,d,j,dp));
        }

        // right (i+1,i+2,....i+d)
        
        for(int j=i+1;j<=min(n-1,i+d);j++){
            if(arr[j]>=arr[i]) break;

            ans=max(ans,1+solve(arr,d,j,dp));
        }

        return dp[i]=ans;
    }
    int maxJumps(vector<int>& arr, int d) {
        int n=arr.size();
            int maxi=INT_MIN;
            vector<int>dp(n+1,-1);
        //all possibility
        for(int i=0;i<n;i++){
            maxi=max(maxi,solve(arr,d,i,dp));
        }
        return maxi;
        
        
    }
};