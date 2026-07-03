class Solution {
public:
    // using dijkastra algorithm
    // using min heap

    bool check(int mid,int n,long long k,vector<vector<pair<int,int>>>&adj){
        // result[i]=min cost path from src to destination
        vector<long long>result(n,LLONG_MAX);

        //min heap
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>pq;
  
        result[0]=0;
        pq.push({0,0});

        while(!pq.empty()){
            long long d=pq.top().first;

            long long node=pq.top().second;

            pq.pop();


            if(d>k){
                return false;
            }

            if(node==n-1){
                return true;
            }

            if(result[node] < d){
            continue;
            }

            for(auto &vec:adj[node]){
                int ngbr=vec.first;
                int cost=vec.second;

                if(cost<mid){
                    continue;
                }
                if(d+cost < result[ngbr]){
                    result[ngbr]=d+cost;

                    pq.push({d+cost,ngbr});
                }
            }
        }

        return false;

    }
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n=online.size();

        vector<vector<pair<int,int>>>adj(n); // adjancy list
        int l=INT_MAX;
        int r=0;

        for(auto &e:edges){
            int u=e[0];
            int v=e[1];
            int cost=e[2];

            if(!online[u] || !online[v]){
                continue;
            }

            adj[u].push_back({v,cost});

            l=min(l,cost);
            r=max(r,cost);


        }

        // using bs

        int ans=-1;

        while(l<=r){
            int mid=l+(r-l)/2;

            if(check(mid,n,k,adj)){
                ans=mid;
                l=mid+1;
            }else{
                r=mid-1;
            }
        }

        return ans;
    }
};