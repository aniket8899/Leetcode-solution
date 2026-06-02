class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {

        int n=landStartTime.size();
        int m=waterStartTime.size();

        int mini=INT_MAX;


     

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                // first start land ride

                int landfinish=landStartTime[i]+landDuration[i];

                int  start=max(landfinish,waterStartTime[j]);
                int total=start+waterDuration[j];

                mini=min(mini,total);


                // first start water ride

                int waterfinish=waterStartTime[j]+waterDuration[j];

                int start1=max(waterfinish,landStartTime[i]);

                int total1=start1+landDuration[i];

                mini=min(mini,total1);


            }
        }

        return mini;
        
    }
};