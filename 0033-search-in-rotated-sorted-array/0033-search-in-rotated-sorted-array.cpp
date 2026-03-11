class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int st=0;
        int ed=n-1;

        while(st<=ed){
            int mid=(st+ed)/2;

            // answe mil gya
            if(nums[mid]==target){
                return mid;
            }

            // left half
            if(nums[st]<=nums[mid]){
                  // answer left side me hoga
                  if(target>=nums[st] && target <=nums[mid]){
                    // left side jao
                    ed=mid-1;
                  }else{
                    st=mid+1;
                  }
            }
            // right half me hoga
            else{
                // ans right side me hoga
                if(target>=nums[mid] && target<=nums[ed]){
                    //right side me jao
                    st=mid+1;
                }else{
                    ed=mid-1;
                }
            }
        }
        return -1;
        
    }
};