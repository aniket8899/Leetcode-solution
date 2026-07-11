class Solution {
public:

    void dfs(int node,vector<vector<int>>&adj,int &node1,int &edge,vector<bool>&visited){
        visited[node]=true;
        node1++;
        edge+=adj[node].size();  // adjacency list me ---->0 : 1 2
                                                     //   1 : 0 2
                                                     //   2 : 0 1  --->> har edge do baar aaya h

        for(auto &ngbr:adj[node]){
            if(!visited[ngbr]){
                dfs(ngbr,adj,node1,edge,visited);
            }
        }

        
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        int cnt=0;
        vector<vector<int>>adj(n);

        for(auto &e:edges){
            int u=e[0];
            int v=e[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool>visited(n,false);

        for(int i=0;i<n;i++){
            if(!visited[i]){
                int node1=0;
                int edge=0;

                dfs(i,adj,node1,edge,visited);

                edge/=2; // edge do baar anan ka chalta edge ko 2 se divide kiya h

                if(edge==node1*(node1-1)/2){
                    cnt++;
                }


            }
        }

        return cnt;






        
    }
};