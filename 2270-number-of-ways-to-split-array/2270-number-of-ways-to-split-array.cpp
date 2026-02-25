class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n=nums.size();
        long long totalsum=0;
        for(int i=0;i<n;i++){
            totalsum+=nums[i];
        }
        long long leftsum=0;
        long long rightsum=0;
        int cnt=0;
        for(int i=0;i<n-1;i++){
            leftsum+=nums[i];
            rightsum=totalsum-leftsum;

            if(leftsum>=rightsum){
                cnt++;
            }
        }
        return cnt;


    }
};