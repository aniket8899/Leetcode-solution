class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        // int low=0,middle=0;
        // int high=n-1;
        // while(middle<=high){
        //     if(nums[middle]==0){
        //         swap(nums[low],nums[middle]);
        //         low++,middle++;
        //     }else if(nums[middle]==1){
        //         middle++;
        //     }else {
        //         swap(nums[middle],nums[high]);
        //         high--;
        //     }
        // }

        int cnt0=0,cnt1=0,cnt2=0;

        for(int i=0;i<n;i++){
            if(nums[i]==0){
                cnt0++;
            }else if(nums[i]==1){
                cnt1++;
            }else{
                cnt2++;
            }
        }
        int index=0;
        while(cnt0--){
            nums[index]=0;
            index++;
        }
         while(cnt1--){
            nums[index]=1;
            index++;
        }
         while(cnt2--){
            nums[index]=2;
            index++;
        }
        
    }
};