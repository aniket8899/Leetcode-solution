class Solution {
public:
    typedef long long ll;
    int m=1e9+7;
    int n;
    int cols;

     vector<vector<int>>ancestortable;
           vector<int>depth;



    ll power(ll base,ll exponent){
        if(exponent==0){
            return 1;
        }

        ll half=power(base,exponent/2);
        ll result=(half*half)%m;

        if(exponent%2==1){
            result=(result*base)%m;
        }

        return result;
    }

    void dfs(int root,int parent, unordered_map<int,vector<int>>&adj){
        ancestortable[root][0]=parent;

        for(auto nbr:adj[root]){
            if(nbr==parent) continue;

            depth[nbr]=depth[root]+1;

            dfs(nbr,root,adj);
        }
    }

    void buildAncestorTable(){
        for(int j=1;j<=cols;j++){
            for(int node=0;node<n;node++){

                if(ancestortable[node][j-1]!=-1){
                ancestortable[node][j]=ancestortable[ ancestortable[node][j-1]] [j-1];
                }
            }
        }
    }

    int findlca(int u,int v){
        if(depth[u] < depth[v]){
            swap(u,v);
        }

        int k=depth[u]-depth[v];

        for(int j=0;j<cols;j++){
            if(k & (1<<j)){
                u=ancestortable[u][j];
            }
        }
        if(u==v) return u;

        for(int j=cols-1;j>=0;j--){
            if(ancestortable[u][j] !=ancestortable[v][j]){
                u=ancestortable[u][j];
                v=ancestortable[v][j];
            }
        }

        return ancestortable[u][0];
    }

    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        n=edges.size()+1;
        cols=log2(n)+1;
        // unordered_map for  stores a neighbours node
        unordered_map<int,vector<int>>adj;
       
  
        vector<int>ans;

        for(auto edge:edges){
            int u=edge[0]-1;
            int v=edge[1]-1;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        depth.resize(n,0);
        ancestortable.resize(n,vector<int>(cols+1,-1));
        dfs(0,-1,adj);
        buildAncestorTable();


        // for queries 
        for(auto query:queries){
            int u=query[0]-1;
            int v=query[1]-1;

            ll lca=findlca(u,v);

            int d=depth[u]+depth[v]-2*depth[lca];

            if(d==0){
                ans.push_back(0);
            }else{
            ans.push_back(power(2,d-1));

            }
        }
        return ans;
    }
};