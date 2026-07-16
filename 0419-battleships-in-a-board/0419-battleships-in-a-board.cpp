class Solution {
public:
    void dfs(int i,int j,vector<vector<char>>& board){
        int n=board.size();
        int m=board[0].size();


        if(i< 0 || j<0 || i>=n || j>=m || board[i][j]=='.'){
            return ;
        }
   
    board[i][j]='.';

    // right
    dfs(i,j+1,board);

    //down
    dfs(i+1,j,board);






    }
    int countBattleships(vector<vector<char>>& board) {

        int cnt=0;

        int n=board.size();
        int m=board[0].size();

        // int cnt=0;


        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='X'){
                    cnt++;

                    dfs(i,j,board);
                }
            }
        }
        return cnt;
    }
};