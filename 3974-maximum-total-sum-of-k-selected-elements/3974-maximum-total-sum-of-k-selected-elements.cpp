class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {

        // max heap
        priority_queue<int>maxheap;

        int n=nums.size();

        for(int i=0;i<n;i++){
            maxheap.push(nums[i]);
        }

        long long ans=0;
        vector<int>st;

        while(k--){
            int top=maxheap.top();
            if(mul>0){
            ans+= 1LL *top*mul;
            }else{
                ans+=top;
            }
        
            mul--;
            maxheap.pop();
           
        }

        return ans;
        
    }
};