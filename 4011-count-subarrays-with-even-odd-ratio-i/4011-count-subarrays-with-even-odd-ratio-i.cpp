class Solution {
public:
    int countRatioSubarrays(vector<int>& nums, int a, int b) {
        
        int n=nums.size();
        

        int cnt=0;

        for(int i=0;i<n;i++){
            int evencnt=0;
            int oddcnt=0;
            for(int j=i;j<n;j++){
                if(nums[j]%2==0){
                    evencnt++;
                }else{
                    oddcnt++;
                }

                int findratio= b*evencnt <=a*oddcnt;

                if(findratio){
                    cnt++;
                }

            }
        }

        return cnt;
    }
};