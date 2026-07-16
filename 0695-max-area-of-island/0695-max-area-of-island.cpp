class Solution {
public:
    int dfs(int i,int j,vector<vector<int>>&grid){
        int n=grid.size();
        int m=grid[0].size();
        // base case
        if(i<0 || j<0 || i>=n ||j>=m || grid[i][j]==0){
            return 0;
        }

        grid[i][j]=0; // har 1 pe jakar visit kar denga

        //up
        return 1+ dfs(i-1,j,grid)+dfs(i+1,j,grid)+dfs(i,j-1,grid)+ dfs(i,j+1,grid);




    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {

        int n=grid.size();
        int m=grid[0].size();

        int cnt=0;


        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                   

                    cnt=max(cnt,dfs(i,j,grid));
                }
            }
        }
        return cnt;
        
    }
};