class Solution {
public:
    int solve(vector<int>&nums,int div){
        int sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            sum+=ceil((double)nums[i]/div);
        }
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        // int maxi=INT_MIN;
        // int n=nums.size();
        // for(int i=0;i<n;i++){
        //     maxi=max(maxi,nums[i]);
        // }

        // for(int i=1;i<=maxi;i++){
        //     int sum=0;
        //     for(int j=0;j<n;j++){
        //        sum += ceil((double)nums[j] / i);

        //     }

        //     if(sum<=threshold){
        //         return i;
        //     }
        // }
        // return -1;

        int st=1;
        int ed=*max_element(nums.begin(),nums.end());
        while(st<=ed){
            int mid=(st+ed)/2;

            if(solve(nums,mid)>threshold){
                st=mid+1;
            }else{
                ed=mid-1;
            }
        }
        return st;
        
    }
};