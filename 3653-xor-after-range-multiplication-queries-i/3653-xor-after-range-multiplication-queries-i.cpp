class Solution {
public:

const int mod=1e9+7;
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n=queries.size();
        int l1,r1,k1,v1;

        for(int i=0;i<n;i++){
             l1=queries[i][0];
             r1=queries[i][1];
             k1=queries[i][2];
             v1=queries[i][3];
        long long  idx=l1;

        while(idx<=r1){
            nums[idx]= ( 1LL *nums[idx]*v1) % mod;

            idx+=k1;
        }
        }


        int xorans=0;

        for(int j=0;j<nums.size();j++){
            xorans^=nums[j];
        }

        return xorans;
        
    }
};