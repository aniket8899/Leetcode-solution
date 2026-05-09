class Solution {
public:

  vector<int>rotatedarr(vector<int>&temp,int k){
    int n=temp.size();

    k=k%n;

    vector<int>ans;

   // process k to n
    for(int i=k;i<n;i++){
        ans.push_back(temp[i]);
    }

    // first process k



    for(int i=0;i<k;i++){
        ans.push_back(temp[i]);
    }

  

    return ans;
  }




    void processlayer(vector<vector<int>>& grid, int k,int i){


        int m=grid.size();
        int n=grid[0].size();

       

        int layer=min(m,n)/2;

       

            int strow=i;
            int stcol=i;
            int endrow=m-i-1;

            int endcol=n-i-1;

            vector<int>temp;

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

      vector<int>rotated=rotatedarr(temp,k);

      int size=rotated.size();
          

          

            int index=0;

             // st row

            for(int i=stcol;i<=endcol;i++){
               grid[strow][i]=rotated[index++];

               if(size==index){
                index=0;
               }
            }


             // ending col

            for(int i=strow+1;i<=endrow-1;i++){
                grid[i][endcol]=rotated[index++];

               if(size==index){
                index=0;
            }
            }
            //ending row

            for(int i=endcol;i>=stcol;i--){
                grid[endrow][i]=rotated[index++];

               if(size==index){
                index=0;
               }
            }
            //st col

            for(int i=endrow-1;i>=strow+1;i--){
                grid[i][stcol]=rotated[index++];

               if(size==index){
                index=0;
               }
            }




    }
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
       

     int m=grid.size();
        int n=grid[0].size();

        int layer=min(m,n)/2;

        for(int i=0;i<layer;i++){
            processlayer(grid,k,i);
        }

        return grid;





        
    }
};