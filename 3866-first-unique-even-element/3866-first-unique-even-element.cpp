class Solution {
public:
    int firstUniqueEven(vector<int>& nums) {
        unordered_map<int,int>mp;

        for(auto num:nums){
            mp[num]++;
        }
        int ans=-1;
       for(auto num:nums){
        if(mp[num]==1 && num%2==0){
            ans=num;
            break;
        }
       }
       return ans;
    }
};