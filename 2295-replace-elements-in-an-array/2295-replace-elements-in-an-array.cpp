class Solution {
public:

/*
 operation  given
 1-3
 4-7
 6-1

*/
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
         vector<int>ans;

         int n=nums.size();

         map<int,int>mp;

         
         for(int i=0;i<n;i++){
            mp[nums[i]]=i;
         }

         for(int i=0;i<operations.size();i++){
            int ft=operations[i][0];
            int sd=operations[i][1];

        int it=mp[ft];
            nums[it]=sd;

            mp.erase(ft);

            mp[sd]=it;

         }

         return nums;
       

      





    }
};