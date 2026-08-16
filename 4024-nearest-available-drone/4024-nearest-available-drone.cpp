class Solution {
public:
    int nearestDrone(vector<vector<int>>& drones, vector<int>& target) {

        int mini= INT_MAX;

        int ans=-1;

        int x1= target[0];
        int y1=target[1];


       int i=0;
        
        for(auto &d:drones){
            int x=d[0];
            int y=d[1];
            int range=d[2];
            


            int findistance=abs(x-x1) +abs(y-y1);

            if(findistance <=range){
               
               if(findistance<mini){
                 mini=findistance;
                 ans=i;
               }

           

            }
            i++;



        }

        return ans;
        
    }
};