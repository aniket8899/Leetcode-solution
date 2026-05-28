class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        vector<int> ans;
        int n=nums.size();
        // int cnt=0;

       map<int,int>mp;

       for(auto num:nums){
        mp[num]++;
       }

       for(auto it:mp){

        int cnt=0;
        int first=it.first;
        int second=it.second;

        for(int i=0;i<second;i++){
            cnt++;
            if(cnt<=k){
                ans.push_back(first);
            }
            
        }
           
       }
    
       return ans;
    }
};