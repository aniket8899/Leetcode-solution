class Solution {
public:
    vector<vector<int>>directions={{0,1},{0,-1},{1,0},{-1,0}};
    bool findSafeWalk(vector<vector<int>>& grid, int health) {

        int n=grid.size();
        int m=grid[0].size();

        vector<vector<int>>result(n,vector<int>(m,INT_MAX));
        // result[i][j] minimum health to reach [0][0] to [i][j]

        deque<pair<int,int>>deq;

        result[0][0]=grid[0][0]; // sourse is 0,0
        deq.push_front({0,0});


        while(!deq.empty()){
            auto [r,c]=deq.front();

            deq.pop_front();


            for(auto &dir:directions){

                int nr=r+dir[0];
                int nc=c+dir[1];

                if(nr< 0 || nr>=n || nc<0 || nc>=m ){ // to check out of bound toh nhi hua n
                    continue;
                }

                if(result[r][c] +grid[nr][nc] < result[nr][nc]){
                        result[nr][nc]=result[r][c] +grid[nr][nc];

                if(grid[nr][nc]==0){
                    deq.push_front({nr,nc});
                }else{
                    deq.push_back({nr,nc});
                }

                }
            }
        }

        int x=result[n-1][m-1];


        return (health-x) >=1;


        
    }
};