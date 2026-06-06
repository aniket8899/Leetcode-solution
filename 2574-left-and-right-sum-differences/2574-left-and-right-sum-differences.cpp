class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {

        int n=nums.size();
        
        vector<int>leftsum;
        vector<int>rightsum;
        leftsum.push_back(0);

        int lsum=0;
        // int rsum=0;
        for(int i=1;i<n;i++){
            lsum+=nums[i-1];

            leftsum.push_back(lsum);
        }

        reverse(nums.begin(),nums.end());

        int rsum=0;
        rightsum.push_back(0);
        for(int i=1;i<nums.size();i++){
            rsum+=nums[i-1];

            rightsum.push_back(rsum);
        }
        reverse(rightsum.begin(),rightsum.end());


        vector<int>ans;

        for(int i=0;i<n;i++){
            ans.push_back(abs(leftsum[i]-rightsum[i]));
        }

        return ans;
    }
};