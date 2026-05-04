class Solution {
public:

    int solve(vector<int>& nums, int goal){
         int n=nums.size();

        int l=0,r=0,sum=0,cnt=0;

        //base
        if(goal < 0) return 0;

        while(r<n){
            sum+=nums[r];

            while(sum>goal){
                sum=sum-nums[l];
                l=l+1;
            }

            cnt=cnt+(r-l+1);
            r=r+1;
        }

        return cnt;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {

       return solve(nums,goal) -solve(nums,goal-1);
        
    }
};