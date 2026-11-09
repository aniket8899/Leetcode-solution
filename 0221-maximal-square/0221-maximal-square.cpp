class Solution {
public:
    int t[301][301];
    int solve(vector<vector<char>>&matrix,int i,int j,int &maxi){
        // bc
        int n = matrix.size();
        int m = matrix[0].size();
        if(i >= n || j >= m){
            return 0;
        }
         if(t[i][j] != -1){
            return t[i][j];
        }

        int right = solve(matrix,i,j+1,maxi);
        int diagonal = solve(matrix,i+1,j+1,maxi);
        int down = solve(matrix,i+1,j,maxi);
       

        if(matrix[i][j] == '1'){
            int ans = 1 + min(right,min(diagonal,down));
            maxi = max(maxi,ans);
            return t[i][j] = ans;
        }else{
            return t[i][j] = 0;
        }
        // return maxi;

    }
    int maximalSquare(vector<vector<char>>& matrix) {
        int maxi = 0;
        int n = matrix.size();
        int m = matrix[0].size();
        memset(t,-1,sizeof(t));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                solve(matrix,i,j,maxi);
            }
        }
        return maxi * maxi;
    }
};