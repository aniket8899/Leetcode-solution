class Solution {
public:
    bool isvalid(vector<vector<char>>& board,int row,int col,char ch){
        //row check

        for(int i=0;i<9;i++){
            if(board[row][i]==ch){
                return false;
            }
            //col check

            if(board[i][col]==ch){
                return false;
            }

            //sub box

            if(board[3*(row/3)+i/3][3*(col/3)+i%3]==ch){
                return false;

            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {

        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){

                if(board[i][j]!='.'){
                    char ch=board[i][j];

                    board[i][j]='.';

                    if(!isvalid(board,i,j,ch)){
                        return false;
                    }

                    board[i][j]=ch;
                }



                
                
            }
        }
        return true;
       

        
    }
};