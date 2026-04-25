class Solution {
public:
    int compareBitonicSums(vector<int>& nums) {
        int n=nums.size();
        long long sum1=0;
        long long sum2=0;


      // binary search
      int st=0;
      int ed=n-1;
      int ansindex=-1;

      while(st<=ed){
        int mid=st+(ed-st)/2;

        if(mid+1 <n && nums[mid] <nums[mid+1]){
            st=mid+1;
        }else{
            ansindex=mid;
            ed=mid-1;
        }
      }

       for(int i=1;i<n;i++){
        //left part
        if(  nums[i-1]<nums[i]){
            sum1+=nums[i-1];
        }
        else if(nums[i-1]>nums[i]){
            sum2+=nums[i];
        }
       }

       long long leftpart=(long long)sum1+nums[ansindex];

       long long rightpart=(long long)sum2+nums[ansindex];

       if(leftpart>rightpart){
        return 0;
       }else if(leftpart <rightpart){
        return 1;
       }
       else{
        return -1;
       }
      
        
 
    }
};