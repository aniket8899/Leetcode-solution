class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int>leftans;

        int n=nums.size();

        // left side handle

        for(int i=0;i<n;i++){
            if(nums[i]<pivot){
                leftans.push_back(nums[i]);
            }
        }

        // middle side handle
        vector<int>middle;

        for(int i=0;i<n;i++){
            if(nums[i]==pivot){
                middle.push_back(nums[i]);
            }
        }

        // left side handle
        vector<int>rightans;

        for(int i=0;i<n;i++){
            if(nums[i]>pivot){
                rightans.push_back(nums[i]);
            }
        }

        //overall
        vector<int>ans;
        for(auto x:leftans){
            ans.push_back(x);
        }

        for(auto x:middle){
            ans.push_back(x);
        }

        for(auto x:rightans){
            ans.push_back(x);
        }

        return ans;

        

    }
};