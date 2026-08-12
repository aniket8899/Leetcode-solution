class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {

        int n=nums.size();

        int i=0,j=0,cnt=0;

        unordered_map<int,int>mp;
        while(j<n){
            mp[nums[j]]++;

            while(mp[nums[j]]>k){
                mp[nums[i]]--;

                // if(mp[nums[i]]==0){
                //     mp.erase(mp[nums[i]]);
                // }
                i++;
            }

            cnt=max(cnt,j-i+1);
            j++;
        }

        return cnt;
        
    }
};