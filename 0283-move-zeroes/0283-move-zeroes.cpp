class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        // vector<int>arr(n,0);
        // int index=0;
        // for(int i=0;i<n;i++){
        //     if(nums[i]!=0){
        //     arr[index]=nums[i];
        //     index++;

        //     }
        // }
        // for(int i=0;i<n;i++){
        //     nums[i]=arr[i];
        // }
        int j=0;
        for(int i=0;i<n;i++){
            if(nums[i]!=0){
                swap(nums[i],nums[j]);
                j++;
            }
        }
        return;
        
    }
};