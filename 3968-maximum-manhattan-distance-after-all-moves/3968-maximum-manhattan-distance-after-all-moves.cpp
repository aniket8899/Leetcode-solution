class Solution {
public:
    int maxDistance(string moves) {
        int cntL=0;
        int cntR=0;
        int cntU=0;
        int cntD=0;
        int cntunderscore=0; // (  _ )


        int n=moves.size();


        for(int i=0;i<n;i++){

            if(moves[i]=='L'){
                cntL++;
            }else if(moves[i]=='R'){
                cntR++;

            }else if(moves[i]=='U'){
                cntU++;
            }else if(moves[i]=='D'){
                    cntD++;
            }else{
                cntunderscore++;
            }
        }


        int x=cntR-cntL;
        int y=cntU-cntD;

        return abs(x) +abs(y)+cntunderscore;




        

        
    }
};