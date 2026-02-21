class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
    
        int n=matrix.size();
        int m=matrix[0].size();

        for(int i=0;i<n;i++){
            if(target>=matrix[i][0] && target <=matrix[i][m-1]){
                // bs
                int st=0;
                int ed=m-1;
                while(st<=ed){
                    int mid=(st+ed)/2;
                    if(matrix[i][mid]==target){
                        return true;
                    }else if(target>matrix[i][mid]){
                        st=mid+1;
                    }else{
                        ed=mid-1;
                    }
                }
            }

        }
        return false;
        
    }
};