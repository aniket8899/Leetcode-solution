class Solution {
public:
    vector<int> concatWithReverse(vector<int>& nums) {
        vector<int>ans;
        int n=nums.size();

        for(int i=0;i<n;i++){
            ans.push_back(nums[i]);
        }

        reverse(nums.begin(),nums.end());

        int x=nums.size();
        for(int i=0;i<x;i++){

        ans.push_back(nums[i]);
        }


        return ans;
        
    }
};