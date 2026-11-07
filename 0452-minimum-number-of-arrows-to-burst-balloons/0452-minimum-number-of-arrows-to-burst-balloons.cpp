class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        int count = 1;

        sort(points.begin(),points.end());
        
        vector<int>prev = points[0];

        for(int i=1;i<n;i++){
            int currpoints = points[i][0];
            int currendpoints = points[i][1];

            int prevpoints = prev[0];
            int endpoints = prev[1];

            if(currpoints > endpoints){
                count++;
                prev = points[i];
            }else{
                prev[0] = max(prevpoints,currpoints);
                prev[1] = min(endpoints,currendpoints);
            }
        }
        return count;
    }
};