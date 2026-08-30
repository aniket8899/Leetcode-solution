class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {

        int n=nums.size();
        int cnt=0;

        vector<int>temp;

        if(n==1 ) return 1;

       for(int i=0;i<n;i++){
        if(i>0 && nums[i]==nums[i-1]){  // duplicate handle
            continue;
        }
        temp.push_back(nums[i]);
       }

       unordered_map<int,int>mp;

       for(auto m:temp){
        mp[m]++;
       }

       for(auto it:mp){
        if(it.second==1){
            cnt++;
        }
       }

        return cnt;

    
        
    }
};