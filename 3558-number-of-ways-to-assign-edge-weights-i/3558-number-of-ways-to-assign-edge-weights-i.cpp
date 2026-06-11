class Solution {
public:
    int m=1e9+7;
    typedef long long ll;
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

    int getmaxdepth(unordered_map<int,vector<int>>&adj, int root,int parent){
        int maxdepth=0;

        for(auto nbr:adj[root]){
            if(nbr==parent) continue;

            maxdepth=max(maxdepth,getmaxdepth(adj,nbr,root)+1);
        }
        return maxdepth;
    }
    int assignEdgeWeights(vector<vector<int>>& edges) {
        // build a adjacency list
        unordered_map<int,vector<int>>adj;

        for(auto edge:edges){
            int u=edge[0];
            int v=edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int d=getmaxdepth(adj,1,-1);

        return power(2,d-1);
        
    }
};