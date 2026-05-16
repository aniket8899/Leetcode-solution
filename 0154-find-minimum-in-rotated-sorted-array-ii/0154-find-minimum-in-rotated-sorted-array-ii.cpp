class Solution {
public:
    int findMin(vector<int>& nums) {

        // int mini=*min_element(nums.begin(),nums.end());

        // return mini;

        int n=nums.size();
        int st=0;
        int ed=n-1;

        while(st<ed){
            while(st< ed && nums[st]==nums[st+1]) st++;

            while(ed> st && nums[ed]==nums[ed-1]) ed--; 
            int mid=st+(ed-st)/2;

            if(nums[mid]>nums[ed]){
                st=mid+1;
            }
            else{
                ed=mid;
            }
        }

        return nums[st];
        
    }
};