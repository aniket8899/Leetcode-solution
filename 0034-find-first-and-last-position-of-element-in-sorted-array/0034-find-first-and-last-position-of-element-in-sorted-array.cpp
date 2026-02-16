class Solution {
public:
    void firstoccurence(vector<int>&arr,int target,int& firstocc){
        int n=arr.size();
        int st=0;
        int end=n-1;
        while(st<=end){
            int mid=(st+end)/2;
            if(arr[mid]==target){
                firstocc=mid;
               end=mid-1;
            }else if(target>arr[mid]){
                st=mid+1;
            }else{
                end=mid-1;
            }
        }

    }
    void secondoccurence(vector<int>&arr,int target,int& secondocc){
       int n=arr.size();
        int st=0;
        int end=n-1;
        while(st<=end){
            int mid=(st+end)/2;
            if(arr[mid]==target){
                secondocc=mid;
                st=mid+1;
            }else if(target>arr[mid]){
                st=mid+1;
            }else{
                end=mid-1;
            }
        }
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>ans(2);
        int firstocc=-1;
        firstoccurence(nums,target,firstocc);
        int secondocc=-1;
        secondoccurence(nums,target,secondocc);
        ans[0]=firstocc;
        ans[1]=secondocc;

        return ans;
    }
};