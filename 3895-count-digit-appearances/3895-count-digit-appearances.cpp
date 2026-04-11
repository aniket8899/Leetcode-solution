class Solution {
public:
    int countDigitOccurrences(vector<int>& nums, int digit) {
        
        int n=nums.size();
        int cnt=0;
        for(int i=0;i<n;i++){
            int num=nums[i];

            while(num){

          int rem=num%10;

          if(rem==digit){
            cnt++;
          }
          num/=10;

            }
        }
        return cnt;
    }
};