class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
          vector<vector<int>>ans;

          int n=intervals.size();

          int first=newInterval[0];
          int second=newInterval[1];

          int i=0;

          while(i<n && intervals[i][1] <first ){ 
            ans.push_back(intervals[i]);
            i++;
          }

          while(i<n && intervals[i][0]<=second){
            newInterval[0]=min(intervals[i][0],newInterval[0]);
            newInterval[1]=max(intervals[i][1],newInterval[1]);

            
            i++;
          }

          ans.push_back(newInterval);

          while(i<n){
            ans.push_back(intervals[i]);
            i++;
          }

          return ans;


    }
};