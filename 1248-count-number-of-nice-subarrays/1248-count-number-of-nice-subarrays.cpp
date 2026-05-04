class Solution {
public:

    int solve(vector<int>& ans, int goal){
         int n=ans.size();

        int l=0,r=0,sum=0,cnt=0;

        //base
        if(goal < 0) return 0;

        while(r<n){
            sum+=ans[r];

            while(sum>goal){
                sum=sum-ans[l];
                l=l+1;
            }

            cnt=cnt+(r-l+1);
            r=r+1;
        }

        return cnt;
    }



    int numberOfSubarrays(vector<int>& nums, int k) {

        int n=nums.size();
        vector<int>ans;

        for(int i=0;i<n;i++){
            if(nums[i]%2!=0){
                ans.push_back(1);
            }else{
                ans.push_back(0);
            }
        }

        return solve(ans,k)-solve(ans,k-1);
        

        
        
    }
};