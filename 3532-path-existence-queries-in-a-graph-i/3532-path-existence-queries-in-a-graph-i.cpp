class Solution {
public:

     // phala jo nums diya h usi help se graph bana le 
     // graph banana ka baad  har ek edge pe dfs chalenga phir usko store karenga

    void dfs(int node,int cnt,vector<vector<int>>&adj,vector<int>&component){
        //first node
        component[node]=cnt;

        for(auto ngbr:adj[node]){
            if(component[ngbr]==-1){
                dfs(ngbr,cnt,adj,component);
            }
        }
    }

    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        // step-1
        // vector<int>components(n,-1);
        // int compid=0;
        // components[0]=compid;

        // for(int i=1;i<n;i++){
        //     if(nums[i]-nums[i-1] >maxDiff){
        //         compid++;
        //     }
        //         components[i]=compid;
            
        // }

        // vector<bool>result;

        // for(auto &q:queries){
        //     int u=q[0];
        //     int v=q[1];

        //     result.push_back(components[u]==components[v]);
        // }

        // return result;




        // step-2 ----->using dfs


        vector<vector<int>>adj(n);

        //build a graph
        for(int i=1;i<n;i++){
            if(nums[i]-nums[i-1] <=maxDiff){
                adj[i].push_back(i-1);
                adj[i-1].push_back(i);
            }
        }

        vector<int>component(n,-1);
        int cnt=0;

        for(int i=0;i<n;i++){
            if(component[i]==-1){
                dfs(i,cnt,adj,component);
                cnt++;
            }
        }

        vector<bool>result;

        for(auto q:queries){
            int u=q[0];
            int v=q[1];

            result.push_back(component[u]==component[v]);
        }

        return result;
    }
};