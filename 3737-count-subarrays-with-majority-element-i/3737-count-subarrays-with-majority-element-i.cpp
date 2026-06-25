class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {

        int n=nums.size();
        int cnt=0;

        // for(int i=0;i<n;i++){
        //     unordered_map<int,int>mp;

        //     for(int j=i;j<n;j++){
        //         mp[nums[j]]++;

        //         int length=j-i+1;

        //         if(mp[target]>length/2){
        //             cnt++;
        //         }
        //     }
        // }

        // for(int i=0;i<n;i++){
        //     int total=0;

        //     for(int j=i;j<n;j++){
        //         if(target==nums[j])
        //             total++;
                

        //         int length=j-i+1;

        //         if(total>length/2){
        //             cnt++;
        //         }
        //     }
        // }

        // return cnt;


        for(int i=0;i<n;i++){
            int total=0;

            for(int j=i;j<n;j++){

                if(nums[j]==target){
                    total+=1;
                }else{
                    total-=1;
                }

                if(total>0){
                    cnt++;
                }
            }
        }
        return cnt;
        
    }
};