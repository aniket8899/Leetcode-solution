class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n=nums.size();
int st=0;
int ed=n-1;
while(st<=ed){
    int mid=(st+ed)/2;

    if(nums[mid]==target){
        return true;
    }
    // left half
    if(nums[st]<=nums[mid]){

            // to check left half to find target
            if(target>=nums[st] && target<=nums[mid]){
                ed=mid-1;
            }else{
                st=mid+1;
            }
    }else{
          if(target>=nums[mid] && target<=nums[ed]){
                st=mid+1;
            }else{
                ed=mid-1;
            }
    }
}


return false;
    }
};