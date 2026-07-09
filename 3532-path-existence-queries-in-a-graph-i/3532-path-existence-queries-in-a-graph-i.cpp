class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int>components(n,-1);
        int compid=0;
        components[0]=compid;

        for(int i=1;i<n;i++){
            if(nums[i]-nums[i-1] >maxDiff){
                compid++;
            }
                components[i]=compid;
            
        }

        vector<bool>result;

        for(auto &q:queries){
            int u=q[0];
            int v=q[1];

            result.push_back(components[u]==components[v]);
        }

        return result;
    }
};