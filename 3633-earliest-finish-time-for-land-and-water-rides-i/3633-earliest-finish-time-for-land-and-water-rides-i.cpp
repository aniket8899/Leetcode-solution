class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {

        int n=landStartTime.size();
        int m=waterStartTime.size();

        int mini=INT_MAX;

        // first start land ride
        for(int i=0;i<n;i++){
            int total=landStartTime[i]+landDuration[i];

            for(int j=0;j<m;j++){
                int start=max(total,waterStartTime[j]);

                int storevalue=start+waterDuration[j];

                mini=min(storevalue,mini);
            }
        }

        // first start water ride

         for(int i=0;i<m;i++){
            int total=waterStartTime[i]+waterDuration[i];

            for(int j=0;j<n;j++){
                int start=max(total,landStartTime[j]);

                int storevalue=start+landDuration[j];

                mini=min(storevalue,mini);
            }
        }

        return mini;
        
    }
};