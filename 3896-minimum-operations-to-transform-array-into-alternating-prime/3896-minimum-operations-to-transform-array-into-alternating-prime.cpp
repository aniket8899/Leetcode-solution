class Solution {
public:
    bool isprime(int n){
        if(n<=1) return false;

        for(int i=2;i*i<=n;i++){
            if(n%i==0){
                return false;
            }

        }
        return true;
    }
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        int cnt=0;

        for(int i=0;i<n;i++){
            // even indics
            if(i%2==0){
                while(!isprime(nums[i])){
                    nums[i]++;
                    cnt++;

                   
                }
            }else{
                //odd indics
                while(isprime(nums[i])){
                    nums[i]++;
                    cnt++;
                }
            }
        }
        return cnt;
        
    }
};