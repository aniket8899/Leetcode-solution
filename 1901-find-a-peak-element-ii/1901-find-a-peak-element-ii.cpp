class Solution {
public:
    int maxelement(vector<vector<int>>& mat,int mid){
        int maxvalue=-1;
        int index=-1;
        for(int i=0;i<mat.size();i++){
           if(mat[i][mid]>maxvalue){
            maxvalue=mat[i][mid];
            index=i;
           }
        }
        return index;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        int st=0;
        int ed=n-1;

        while(st<=ed){
            int mid=(st+ed)/2;
            int matrowindex=maxelement(mat,mid);

            int leftside=mid-1>=0 ? mat[matrowindex][mid-1]:-1;
            int rightside=mid+1<n?mat[matrowindex][mid+1]:-1;

            if(mat[matrowindex][mid] > leftside && mat[matrowindex][mid]>rightside){
                return {matrowindex,mid};
            }else if(mat[matrowindex][mid]<leftside){
                ed=mid-1;
            }else{
                st=mid+1;
            }
        }
        return {-1,-1};
    }
};