class Solution {
public:

/*
1->2,
0->1,
3->2

graph= 0->1->2
       3->2

    k is given us node me bug h

    k=1 me bug h

    suspicious =1->2
    remaining=0,3 bacha hua h --->outside h

    ab ham 1 aur 2 ko delete karna chchta h

    o->? (agar 1 ko delete kar diya)
    3->? (agar 2 ko delete kar diya)

    iseleiya 1 aur 2 ko delete karna allowed nhi h

*/



     void dfs(int src,vector<vector<int>>&adj,vector<bool>&visited){

        visited[src]=true;

        for(auto ngbr:adj[src]){
            if(!visited[ngbr]){
                dfs(ngbr,adj,visited);
            }
        }
     }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {

        

        vector<bool>visited(n,false);

            vector<vector<int>>adj(n+1);

            for(auto i:invocations){
                int u=i[0];
                int v=i[1];

                adj[u].push_back(v);
            }

            dfs(k,adj,visited);

            // outside-->suspicious

            for(auto i:invocations){
                int u=i[0];
                int v=i[1];

                if(!visited[u] && visited[v]){
                    vector<int>ans;

                    for(int i=0;i<n;i++)
                        ans.push_back(i);
                    

                      return ans;
                }

                
            }

            // suspicious mhi h -- remove suspicious 

            vector<int>ans;

            for(int i=0;i<n;i++){
                if(!visited[i]){
                    ans.push_back(i);
                }
            }

            return ans;


      




        
    }
};