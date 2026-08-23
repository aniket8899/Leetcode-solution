class Solution {
public:
    bool solve(vector<int>& nums,int target,int i,vector<vector<int>>&dp){
        // base case
        if(target==0) return true;
        if(target < 0 || i==nums.size()) return false;

        if(dp[target][i]!=-1){
            return dp[target][i];
        }

        // include
        bool include=solve(nums,target-nums[i],i+1,dp);

        // exclude
        bool exclude=solve(nums,target,i+1,dp);

        return dp[target][i] = include|| exclude;
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        int totalsum=sum;
        // to check odd
        if(totalsum%2!=0){
            return false;
        }
        int target=totalsum/2;
        vector<vector<int>>dp(target+1,vector<int>(n+1,-1));
        return solve(nums,target,0,dp);
    }
};