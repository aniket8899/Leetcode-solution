class Solution {
public:
    int solve(vector<int>&arr,int target,int i,vector<vector<int>>&dp){
        //base case
        if(i==arr.size()){
            if(target==0){
                return 1;
            }
            return 0;
        }

        if(dp[i][target]!=-1){
            return dp[i][target];
        }

        //include
        int include=0;

        if(arr[i]<=target){
            include=solve(arr,target-arr[i],i+1,dp);
        }

        //exclude
        int exclude=solve(arr,target,i+1,dp);


        return dp[i][target] =(include+exclude);
    }
    int perfectsum(vector<int>&arr,int target){
        int n=arr.size();

        vector<vector<int>>dp(n,vector<int>(target+1,-1));
        return  solve(arr,target,0,dp);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int totalsum=0;
        for(int i=0;i<nums.size();i++){
            totalsum+=nums[i];
        }

        //check
        if(totalsum-target<0 || (totalsum-target) %2!=0)
        return false;

        return perfectsum(nums,(totalsum-target)/2);
        
    }
};