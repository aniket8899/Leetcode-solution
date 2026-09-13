class Solution {
public:
    int solve(vector<vector<int>>& img1, vector<vector<int>>& img2,int &row_off,int &col_off){
        int n=img1.size();
        int cnt=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                // to find a indics and check this is overlpa or not

                // a[i][j] ---b[i+row_off][j+col_off]

                int b_i=i+row_off;
                int b_j=j+col_off;

                if(b_i <0 || b_i >=n || b_j <0 || b_j>=n) continue;

                if(img1[i][j]==1 && img2[b_i][b_j]==1){
                    cnt++;
                }
            }
        }

        return cnt;
    }
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int maxi=0;
        int n=img1.size();

        for(int row_off=-n+1;row_off<n;row_off++){
            for(int col_off=-n+1;col_off<n;col_off++){
                int cnt=solve(img1,img2,row_off,col_off);

                maxi=max(maxi,cnt);
            }
        }

        return maxi;
        
    }
};