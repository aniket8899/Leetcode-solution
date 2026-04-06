class Solution {
public:
    void solve(int i,vector<int>& arr, int target, vector<vector<int>>&ans,vector<int>&ds){
        //base case
       
            if(target==0){
                ans.push_back(ds);
                return;
            }
         
         if(i==arr.size()) return;


    // pick
    // for(int j=i;j<arr.size();j++){

        // skip duplicate
        // if(j> i && arr[j]==arr[j-1]) continue;

        if(arr[i]<=target){
            ds.push_back(arr[i]);
            solve(i+1,arr,target-arr[i],ans,ds);
            ds.pop_back();
        }

        int j=i;
        while(j+1 < arr.size() && arr[j] ==arr[j+1]) j++;

        //unpick
    solve(j+1,arr,target,ans,ds);


    
        
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
         vector<vector<int>>ans;
         vector<int>ds;

         sort(candidates.begin(),candidates.end());


         solve(0,candidates,target,ans,ds);
         return ans;
    }
};