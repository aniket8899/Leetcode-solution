class Solution {
public:
    int solve(vector<int>&nums,int i,int previndex, vector<vector<int>>&dp){
        // base case
        if(i==nums.size()){
            return 0;
        }
        if(dp[i][previndex+1]!=-1){
            return dp[i][previndex+1];
        }
        //include
        int include=0;
        if(previndex==-1 || nums[i]>nums[previndex]){
            include=1 +solve(nums,i+1,i,dp);
        }

        //exclude
        int exclude=solve(nums,i+1,previndex,dp);

        return dp[i][previndex+1]= max(include,exclude);
    }
    int optimal(vector<int>&nums){
        int n=nums.size();

        vector<int>ans;
        ans.push_back(nums[0]);  //push first element

        for(int i=1;i<n;i++){
            if(nums[i]>ans.back()){
                ans.push_back(nums[i]);
            }else{
                int index=lower_bound(ans.begin(),ans.end(),nums[i])-ans.begin();
                ans[index]=nums[i];
            }
        }
        return ans.size();
    }

    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        // return solve(nums,0,-1,dp);

        return optimal(nums);
        
    }
};