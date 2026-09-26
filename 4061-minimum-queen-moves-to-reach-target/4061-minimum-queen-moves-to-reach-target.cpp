class Solution {
public:
    int solve(int i,int j,vector<int>&source,vector<int>&target){
        // base case

        int sr=source[0];
        int sc=source[1];


        int tr=target[0];
        int tc=target[1];
        if(source==target){
            return 0;
        }

        int down=1+solve(i+1,j,source,target);
        int left=1+solve(i,j+1,source,target);
        int diagonal=1+solve(i+1,j+1,source,target);

        return min({down,left,diagonal});


    }
    int minQueenMoves(vector<int>& source, vector<int>& target) {

        

        int sr=source[0];
        int sc=source[1];


        int tr=target[0];
        int tc=target[1];

        // if(sr==tr && sc==tc){
        //     return 0;
        // }else if(sr==tr){
        //     return 1;
        // }else if(sc==tc){
        //     return 1;
        // }else if(abs(sr-tr)==abs(sc-tc)){
        //     return 1;
        // }else{
        //     return 2;
        // }


          if(sr==tr && sc==tc){
            return 0;
        }else if(sr==tr){
            return 1;
        }else if(sc==tc){
            return 1;
        }else if(abs(sr-tr)==abs(sc-tc)){
            return 1;
        }else{
            return 2;
        }
        
       
    }
};