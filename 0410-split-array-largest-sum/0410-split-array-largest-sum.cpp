class Solution {
public:
    int solve(vector<int>&nums,int split){
        int splitnumber=1;
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            if(cnt+nums[i]>split){
                splitnumber++;
                cnt=nums[i];
            }else{
                cnt+=nums[i];
            }
        }
        return splitnumber;
    }
    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();
        int st=*max_element(nums.begin(),nums.end());
         int totalsum=0;
         for(int i=0;i<n;i++){
            totalsum+=nums[i]; 
         }
         int ed=totalsum;
         int ans=totalsum;
         while(st<=ed){
            int mid=st+(ed-st)/2;

            if(solve(nums,mid)<=k){
                ans=mid;
                ed=mid-1;
            }else{
                st=mid+1;
            }
         }
         return ans;
    }
};