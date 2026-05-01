class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {

        // // brute force
        // int n=nums.size();
        // int maxlen=0;

       
        // int len=0;

        // for(int i=0;i<n;i++){
        //      int zeros=0;
        //     for(int j=i;j<n;j++){
        //         if(nums[j]==0){
        //             zeros++;

        //         }
        //         if(zeros<=k){
        //             len=j-i+1;
        //            maxlen=max(maxlen,len);
        //         }else{
        //             break;
        //         }
        //     }

        // }

        // return maxlen;


        // two pointer

        int n=nums.size();

        int l=0,r=0,maxlen=0;

        int zero=0;
        while(r<n){
            if(nums[r]==0){
                zero++;
            }
            while(zero>k){
                if(nums[l]==0){
                    zero--;
                }
                l++;
            }

            if(zero<=k){
                int len=r-l+1;
                maxlen=max(maxlen,len);
            }

            r++;
        }

        return maxlen;
        
    }
};