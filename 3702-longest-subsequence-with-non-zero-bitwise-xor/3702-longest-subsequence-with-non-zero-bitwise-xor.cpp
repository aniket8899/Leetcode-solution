class Solution {
public:


/*
  ek corner case  agar pura nums={0,0,0,0,0} ho tab output {0} hi ayega


*/

    int longestSubsequence(vector<int>& nums) {
        int n=nums.size();

        int result=0;
        int cnt=0;

        for(int i=0;i<n;i++){
            result=(result^nums[i]);


            if(nums[i]!=0){
                cnt++;
            }
        }

        if(cnt==0){
            return 0;
        }
       



        if(result==0){
            return n-1;
        }else{
            return n;
        }
    }
};