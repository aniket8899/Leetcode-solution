class Solution {
public:

/*
 
 we have 3 scenorio to delete a elemnt

  first is we delete a element maxi and mini is front side
  second is we delete a element maxi and mini is back side

  third is  delete a element a front ya back side

  // 1--10
  //5--1

  n=8
  leftside=1
  rightside=5
  leftside+8-5
  1+8-5= 4+1=5

  // formula leftside+1+n-rightside


*/
    int minimumDeletions(vector<int>& nums) {

        int n=nums.size();

        if(n==1) return 1;

        // first scenorio

        int minindex=-1;
        int mini=INT_MAX;
        int maxindex=-1;
        int maxi=INT_MIN;


        for(int i=0;i<n;i++){
            if(nums[i]>maxi){
                maxi=nums[i];
                maxindex=i;
            }
        }
        cout<<maxindex;

        for(int i=0;i<n;i++){
            if(nums[i]<mini){
                mini=nums[i];
                minindex=i;
            }
        }

        cout<<minindex;


        int left=min(minindex,maxindex); // 0,1,8,-2,-3,-4,19,5  // min=5
        int right=max(minindex,maxindex);//6


        return min({(left+1)+(n-right),right+1,n-left});



        




        
    }
};