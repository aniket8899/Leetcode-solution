class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int maxi=INT_MIN;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i!=j)
                {
                 maxi=max((nums[i]-1)*(nums[j]-1),maxi);
                }
               
            }
        }
        return maxi;
    }
};