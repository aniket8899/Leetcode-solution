class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {

       restrictions.push_back({1,0}); // first building must be zero
       restrictions.push_back({n,n-1}); // n per restriction nhi h
       sort(restrictions.begin(),restrictions.end());

       //left to right pass

       for(int i=1;i<restrictions.size();i++){
            int distance=restrictions[i][0] -restrictions[i-1][0];

            // left se aana tak max possible
            restrictions[i][1] =min(restrictions[i][1],restrictions[i-1][1]+distance);
       }
        

        // right to left

        for(int i=restrictions.size()-2;i>=0;i--){
            int distance=restrictions[i+1][0] -restrictions[i][0];

            restrictions[i][1]=min(restrictions[i][1],restrictions[i+1][1]+distance);
        }

        int m=restrictions.size();
        long long ans=0;

        for(int i=1;i<m;i++){
            int id1=restrictions[i-1][0];
            int h1=restrictions[i-1][1];


            int id2=restrictions[i][0];
            int h2=restrictions[i][1];

            int distance=id2-id1;

            long long peak=(1LL * h1+h2+distance)/2;

            ans=max(ans,peak);

        }
        return (int)ans;


    }
};