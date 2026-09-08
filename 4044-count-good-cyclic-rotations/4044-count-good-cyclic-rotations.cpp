class Solution {
public:

/*
 
 1,2,3,4,5,6, 1,2,3,4,5,6 

 total sum=21;








*/


    int countGoodRotations(vector<int>& nums) {

        int n=nums.size();

        long long totalsum=0;

        for(int i=0;i<n;i++){
            totalsum+=nums[i];
        }

        long long half=n/2;
        long long first=0;

        for(int i=0;i<n/2;i++){
            first+=nums[i];
        }

        int cnt=0;


        for(int i=0;i<n;i++){
            long long second=totalsum-first;

            if(first>second){
                cnt++;
            }

            // shrink

            first-=nums[i];

            first+=nums[(i+half)%n];
        }


        return cnt;



       
        



        
    }
};