class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {

        int n=intervals.size();
        int cnt=0;

        sort(intervals.begin(),intervals.end(),[](vector<int>&a,vector<int>&b){  //increasing order
            if(a[0]==b[0]) {
                return a[1]>b[1];
            }
            return a[0]<b[0];
        });
        

            int first1=intervals[0][0];
            int first2=intervals[0][1];

        for(int i=1;i<n;i++){

            int second1=intervals[i][0];
            int second2=intervals[i][1];


            if(first1<=second1 && second2<=first2){
                cnt++;
            }else{
                first1=second1;
                first2=second2;
            }
        }

        return n-cnt;
        
    }
};