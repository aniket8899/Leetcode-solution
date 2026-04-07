class Solution {
public:
    void solve(int k,int n,vector<vector<int>>&ans,vector<int>&ds,int sum,int i){
        //base case
        if(k==ds.size()){
            if(sum==n){
                ans.push_back(ds);
            }
            return;
        }

        for(int j=i+1;j<=9;j++){
            ds.push_back(j);

            solve(k,n,ans,ds,sum+j,j);
            ds.pop_back();
        }



    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;

        vector<int>ds;

        solve(k,n,ans,ds,0,0);
        return ans;
        
    }
};