class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {

        int n=moves.size();
        int cntR=0;
        int cntL=0;
        int cnt1=0;

        for(int i=0;i<n;i++){
            if(moves[i]=='R'){
                cntR++;
            }else if(moves[i]=='L'){
                cntL++;
            }else{
                cnt1++;
            }

        }

        int total=abs(cntR-cntL);

        return total+cnt1;
        
    }
};