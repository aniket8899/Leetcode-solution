class Solution {
public:
    void dfs(int node,vector<vector<pair<int,int>>>&adj, vector<bool>&visited,int &ans){
        // first node visit
        visited[node]=true; 


        for(auto &p:adj[node]){
            int ngbr=p.first;
            int score=p.second;


            ans=min(ans,score);

            if(visited[ngbr]==false){
                dfs(ngbr,adj,visited,ans);
            }


        }
    }
    int minScore(int n, vector<vector<int>>& roads) {
        // int n=roads.size();
    
     vector<vector<pair<int,int>>>adj(n+1); //adjacncy list


     for(auto &ad:roads){
        int u=ad[0];
        int v=ad[1];
        int dist=ad[2];

        adj[u].push_back({v,dist});
        adj[v].push_back({u,dist});
     }

     int ans=INT_MAX;
     vector<bool>visited(n+1,false);


     dfs(1,adj,visited,ans);

     return ans;



        
        
    }
};