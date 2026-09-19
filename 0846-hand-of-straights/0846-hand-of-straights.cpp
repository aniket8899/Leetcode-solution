class Solution {
public:

/*

min heap  == 1,2,2,3,3,4,6,7,8
  
1=1,
2=2,
3=2,
4=1,
6=1,
7=1,
8=1


*/
    bool isNStraightHand(vector<int>& hand, int groupSize) {

        unordered_map<int,int>mp;

        for(auto h:hand){
            mp[h]++;
        }
      



        priority_queue<int,vector<int>,greater<int>>pq;

       for(int i=0;i<hand.size();i++){
        pq.push(hand[i]);
       }


        while(!pq.empty()){
            int top=pq.top();

            pq.pop();

                if(mp[top]==0) continue;

            for(int i=0;i<groupSize;i++){
                int findel=top+i;

                if(mp[findel]==0){
                    return false;
                }

             mp[findel]--;

            }
        }

        return true;

        

       



    }
};