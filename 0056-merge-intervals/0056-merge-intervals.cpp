class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
         vector<vector<int>>ans;
         sort(intervals.begin(),intervals.end());
         ans.push_back(intervals[0]);

         for(int i=1;i<intervals.size();i++){
            int second=intervals[i][0];
            if(ans.back()[1]>=second){
                ans.back()[1]=max(ans.back()[1],intervals[i][1]);
            }else{
                ans.push_back(intervals[i]);
            }
         }
         return ans;
    }
};