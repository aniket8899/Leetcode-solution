class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {

        int n=nums.size();
        
        // vector<int>leftsum;
        // vector<int>rightsum;
        // leftsum.push_back(0);

        // int lsum=0;
        // // int rsum=0;
        // for(int i=1;i<n;i++){
        //     lsum+=nums[i-1];

        //     leftsum.push_back(lsum);
        // }

        // reverse(nums.begin(),nums.end());

        // int rsum=0;
        // rightsum.push_back(0);
        // for(int i=1;i<nums.size();i++){
        //     rsum+=nums[i-1];

        //     rightsum.push_back(rsum);
        // }
        // reverse(rightsum.begin(),rightsum.end());


        // vector<int>ans;

        // for(int i=0;i<n;i++){
        //     ans.push_back(abs(leftsum[i]-rightsum[i]));
        // }

        // return ans;


        vector<int>leftsum(n,0);
        

        for(int i=1;i<n;i++){
            leftsum[i]=leftsum[i-1]+nums[i-1];
        }

        //right sum

        vector<int>rightsum(n,0);

        for(int i=n-2;i>=0;i--){
            rightsum[i]=rightsum[i+1]+nums[i+1];
        }

        vector<int>ans(n,0);

        for(int i=0;i<n;i++){
            ans[i]=abs(leftsum[i]-rightsum[i]);
        }
        return ans;
    }
};