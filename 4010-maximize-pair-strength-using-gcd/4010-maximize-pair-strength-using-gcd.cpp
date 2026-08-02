class Solution {
public:
    long long maxPairStrength(vector<int>& nums) {

        int n=nums.size();

        long long ans=0;

        for(long long i=0;i<n;i++){
            for(long long j=i+1;j<n;j++){
                long long find=gcd(nums[i],nums[j]);
                long long gcdans=find*find;
                long long res=( 1LL*nums[i]* nums[j]);
                long long result= res /gcdans;

                ans=max(ans,result);
            }
        }

        return ans;
        
    }
};