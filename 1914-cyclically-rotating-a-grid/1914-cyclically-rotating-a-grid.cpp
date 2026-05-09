class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();

        int strow=0;//top row
        int endrow=m-1; // bottom row
        int  stcol=0;// st col
        int endcol=n-1; //endcol

        int layer=min(m,n)/2;

        for(int i=0;i<layer;i++){
            vector<int>temp;

            int strow=i;
            int stcol=i;
            int endrow=m-i-1;

            int endcol=n-i-1;

            // st row

            for(int i=stcol;i<=endcol;i++){
                temp.push_back(grid[strow][i]);
            }

            // ending col

            for(int i=strow+1;i<=endrow-1;i++){
                temp.push_back(grid[i][endcol]);
            }
            //ending row

            for(int i=endcol;i>=stcol;i--){
                temp.push_back(grid[endrow][i]);
            }
            //st col

            for(int i=endrow-1;i>=strow+1;i--){
                temp.push_back(grid[i][stcol]);
            }

            int size=temp.size();

            int st=k%size;

            int index=st;

             // st row

            for(int i=stcol;i<=endcol;i++){
               grid[strow][i]=temp[index++];

               if(size==index){
                index=0;
               }
            }


             // ending col

            for(int i=strow+1;i<=endrow-1;i++){
                grid[i][endcol]=temp[index++];

               if(size==index){
                index=0;
            }
            }
            //ending row

            for(int i=endcol;i>=stcol;i--){
                grid[endrow][i]=temp[index++];

               if(size==index){
                index=0;
               }
            }
            //st col

            for(int i=endrow-1;i>=strow+1;i--){
                grid[i][stcol]=temp[index++];

               if(size==index){
                index=0;
               }
            }





        }

        return grid;






        
    }
};