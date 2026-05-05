class Solution {
public:
unordered_map<int ,bool>rowcheck;
unordered_map<int ,bool>lowerdiagonalcheck;
unordered_map<int ,bool>upperdiagonalcheck;

// bool issafe(int row,int col){
//     if(rowcheck[row]==true){
//         return false;
//     }
//     if(lowerdiagonalcheck[row+col]==true){
//         return false;
//     }
//     if(upperdiagonalcheck[row-col]==true){
//         return false;
//     }
//     return true;
// }


//     void solve(int col,int n,int &count){
//         if(col==n){
//             count++;
//             return;
//         }
//         for(int row=0;row<n;row++){
//             if(issafe(row,col)){
//                 rowcheck[row]=true;
//                 lowerdiagonalcheck[row+col]=true;
//                 upperdiagonalcheck[row-col]=true;

//                 solve(col+1,n,count);

//                  rowcheck[row]=false;
//                 lowerdiagonalcheck[row+col]=false;
//                 upperdiagonalcheck[row-col]=false;
//             }
//         }
//     }


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

 void solve(int n, vector<vector<char>>&board,int i,int& cnt){
        // base case
        if(i==n){
            cnt++;
            return;
        }

        for(int row=0;row<n;row++){
            if(issafe(row,board,i,n)){
                board[row][i]='Q';

                solve(n,board,i+1,cnt);

                // backtrack
                board[row][i]='.';
            }
        }
    }





    int totalNQueens(int n) {

        int col=0;
        int count=0;
         vector<vector<char>>board(n,vector<char>(n,'.'));
        solve(n,board,col,count);
        return count;
        
    }
};