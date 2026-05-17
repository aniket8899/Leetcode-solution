class Solution {
public:
    bool solve(vector<int>&arr,int i,vector<bool>&visited){
        int n=arr.size();
        //base case

        if(i< 0 || i>=n ){
            return false;
        }

        //already visited
        if(visited[i]){
            return false;
        }

        if(arr[i]==0){
            return true;
        }

        visited[i]=true;

        bool ans1=solve(arr,i+arr[i],visited);
        bool ans2=solve(arr,i-arr[i],visited);

        return ans1||ans2;
    }
    bool canReach(vector<int>& arr, int start) {
        int n=arr.size();

        vector<bool>visited(n,false);

        return solve(arr,start,visited);
        
    }
};