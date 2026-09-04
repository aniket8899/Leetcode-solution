class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();

        vector<int>prefixsum(n);
        vector<int>suffixsum(n);

        prefixsum[0]=nums[0];

        for(int i=1;i<n;i++){
            prefixsum[i]=max(prefixsum[i-1],nums[i]);
        }

        suffixsum[n-1]=nums[n-1];

        for(int i=n-2;i>=0;i--){
            suffixsum[i]=min(suffixsum[i+1],nums[i]);
        }


        for(int i=0;i<n;i++){
            if(prefixsum[i]-suffixsum[i] <=k){
                return i;
            }
        }
        return -1;

        

        
        
    }
};