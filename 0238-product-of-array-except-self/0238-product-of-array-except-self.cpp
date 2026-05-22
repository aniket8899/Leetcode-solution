class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n);

        vector<int>leftside(n);
        vector<int>rightside(n);


        // int product=1;
        leftside[0]=1;

        for(int i=1;i<n;i++){
            leftside[i]=nums[i-1]*leftside[i-1];
        }

        //rightside 
        rightside[n-1]=1;
        // int product1=1;

        for(int i=n-2;i>=0;i--){
            rightside[i]=nums[i+1] *rightside[i+1];

        }
        
        // reverse(rightside.begin(),rightside.end());

        for(int i=0;i<n;i++){
            ans[i]=leftside[i] *rightside[i];
        }

        return ans;
    }
};