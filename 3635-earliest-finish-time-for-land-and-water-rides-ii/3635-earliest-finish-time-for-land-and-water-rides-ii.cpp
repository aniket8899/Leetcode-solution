class Solution {
public:
    int finishtime(vector<int>& start1,vector<int>& duration1,vector<int>&start2,vector<int>& duration2){

        // activity-1 land ride
        int finish1=INT_MAX;
        for(int i=0;i<start1.size();i++){
            finish1=min(finish1,start1[i]+duration1[i]);
        }

        // activity-2 water ride
        int finish2=INT_MAX;
        for(int i=0;i<start2.size();i++){
            finish2=min(finish2,max(finish1,start2[i])+duration2[i]);
        }
        return finish2;
    }
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {

        int result1=finishtime(landStartTime,landDuration,waterStartTime,waterDuration);
        int result2=finishtime(waterStartTime,waterDuration,landStartTime,landDuration);

        return min(result1,result2);
        
    }
};