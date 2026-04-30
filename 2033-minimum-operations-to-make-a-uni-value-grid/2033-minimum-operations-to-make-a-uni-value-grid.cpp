class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        
        vector<int>result;

        int n=grid.size();
        int m=grid[0].size();

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                result.push_back(grid[i][j]);
            }
        }

        sort(result.begin(),result.end());

        int median=result[result.size()/2];  // median pe ka value find kiya h

        int oper=0;


        for(int i=0;i<result.size();i++){
            int num=result[i];
            int diff=abs(median-num);
            if(diff%x!=0){
                return -1;
            }else{
                oper+=abs(num-median)/x;
            }

        

        }
        return oper;
    }
};