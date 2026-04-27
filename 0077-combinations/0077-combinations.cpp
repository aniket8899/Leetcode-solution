class Solution {
public:
    void solve(int n,int k,vector<vector<int>>&ans,vector<int>&output,int i){
        //base case
        if(k==0){
           ans.push_back(output);
           return;
        }

       for(int j=i;j<=n;j++){
        output.push_back(j);

        solve(n,k-1,ans,output,j+1);

        output.pop_back();
       }



    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int>output;

         solve(n,k,ans,output,1);
         return ans;
    }
};