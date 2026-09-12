class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {

        int n=intervals.size();

        sort(intervals.begin(),intervals.end(),[](vector<int>&a,vector<int>&b){
            return a[1]<b[1];
        });

        int cnt=1;

        int first=intervals[0][1];

            

        for(int i=1;i<n;i++){
           int second=intervals[i][0];

            if(first<=second){
                cnt++;

                first=intervals[i][1];
            }
        }

        return n-cnt;
        
    }
};