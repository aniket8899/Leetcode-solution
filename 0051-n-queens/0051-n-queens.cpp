class Solution {
public:
    void addsolution( vector<vector<char>>&board,vector<vector<string>>&ans,int n){
        vector<string>temp;

        for(int i=0;i<n;i++){
            string output="";
            for(int j=0;j<n;j++){
                output.push_back(board[i][j]);
            }
            temp.push_back(output);
        }

        ans.push_back(temp);

    }

    bool issafe(int row,vector<vector<char>>&board,int col,int n){
        int x=row;
        int y=col;
        while(y>=0){
            // row check
            if(board[x][y]=='Q'){
                return false;
            }
            y--;
        }
        // check upperdiagonal
        x=row;
        y=col;
        while(x>=0 && y>=0){
            if(board[x][y]=='Q'){
                return false;
            }
            x--;
            y--;
        }
        // check lower diagonal
        x=row;
        y=col;

        while(x<n && y>=0){
            if(board[x][y]=='Q'){
                return false;
            }
            x++;
            y--;
        }
        return true;
    }
    void solve(int n,vector<vector<string>>&ans, vector<vector<char>>&board,int i){
        // base case
        if(i==n){
            addsolution(board,ans,n);
            return;
        }

        for(int row=0;row<n;row++){
            if(issafe(row,board,i,n)){
                board[row][i]='Q';

                solve(n,ans,board,i+1);

                // backtrack
                board[row][i]='.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
         vector<vector<string>>ans;
         vector<vector<char>>board(n,vector<char>(n,'.'));
         solve(n,ans,board,0);

         return ans;
    }
};