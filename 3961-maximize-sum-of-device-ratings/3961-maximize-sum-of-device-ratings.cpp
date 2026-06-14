class Solution {
public:

// question bol rha h ki har row ka minimum rating h usme se minimum hata ka dusro me add karo do aur maximize kar do



    long long maxRatings(vector<vector<int>>& units) {

    int n=units[0].size();

        if(n==1){
            long long ans=0;
            for(auto &row:units){
                ans+=row[0];
            }
            return ans;
        }
        int globalmin=INT_MAX;
        int secondsmallest=INT_MAX;
        long long secondsum=0;
        for(auto &row:units){
        sort(row.begin(),row.end());

        // har row ka minimum find kar rha h
        

        int mini=row[0];
        int secondmin=row[1];
       
        globalmin=min(globalmin,mini);

        secondsmallest=min(secondsmallest,secondmin);
        secondsum+=row[1];





        }

        return globalmin+secondsum-secondsmallest;


        
    }
};