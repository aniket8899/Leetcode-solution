class Solution {
public:
//  #typedef ll from long long;
    long long maxTotalValue(vector<int>& nums, int k) {
        int n=nums.size();
        int maxi=INT_MIN;
        int mini=INT_MAX;

        for(int i=0;i<n;i++){
            maxi=max(maxi,nums[i]);
            mini=min(mini,nums[i]);
        }

        return 1l *k*(maxi-mini);

        
    }
};