class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n=nums.size();
        // int maxi=INT_MIN;

        int maxi=*max_element(nums.begin(),nums.end());



        // for(int i=0;i<n;i++){
        //     maxi=max(maxi,nums[i]);
        // }

        // if(maxi!=n-1){
        //     return false;
        // }

        unordered_map<int,int>mp;
        for(auto &num:nums){
            mp[num]++;
        }

        for(int i=1;i<maxi;i++){
            if(mp[i]!=1){
                return false;
            }

        }
            
        return mp[maxi]==2;

        

        
    }
};