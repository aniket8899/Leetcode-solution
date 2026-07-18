class Solution {
public:
    int subarrayGCD(vector<int>& nums, int k) {

        int n=nums.size();

        int cnt=0;

        for(int i=0;i<n;i++){
            int result=0;
            for(int j=i;j<n;j++){

                 result=gcd(result,nums[j]);


                if(result==k){
                    cnt++;
                }
            }
        }
        return cnt;
        
    }
};