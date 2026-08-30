class Solution {
public:
    int solve(vector<int>&nums,int i,int sum,vector<vector<int>>&dp){
        if(sum==0) return 0;
        if( sum <0 ||i==nums.size()) return INT_MAX;



        int ans=INT_MAX;

        if(dp[i][sum]!=-1){
            return dp[i][sum];
        }


        // pick aur unpick

        int pick=solve(nums,i+1,sum-nums[i],dp);

        
        ans=min(ans,pick);

        

        int unpick=solve(nums,i+1,sum,dp);

        ans=min(ans,unpick);



        // multiply

        // int i=1;
        long long newnum = 1LL * nums[i] * 2;
        int cost=1;
        while(newnum<=sum){
            int take=solve(nums,i+1,sum-newnum,dp);


           if(take!=INT_MAX){

            ans=min(ans,cost+take);
            }
            newnum*=2;
            cost++;
        }

        // divide

         newnum=nums[i]/2;
         cost=1;

        while(newnum>0){
            int take=solve(nums,i+1,sum-newnum,dp);

            if(take!=INT_MAX){

            ans=min(ans,cost+take);
            }
            newnum/=2;

            cost++;
        }


        return dp[i][sum]= ans;
    }
    int minOperations(vector<int>& nums, int sum) {

        int n=nums.size();

        vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));

        int ans= solve(nums,0,sum,dp);

        if(ans==INT_MAX){
            return -1;
        }

        return ans;
        
    }
};