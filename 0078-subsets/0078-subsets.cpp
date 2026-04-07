class Solution {
public:
    void solve(vector<int>&nums,vector<vector<int>>&ans,vector<int>&ds,int i){
        // base case
        ans.push_back(ds);


        for(int j=i;j<nums.size();j++){
        ds.push_back(nums[j]);
        solve(nums,ans,ds,j+1);
        ds.pop_back();

        }




    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>ds;

        solve(nums,ans,ds,0);
        return ans;
    }
};