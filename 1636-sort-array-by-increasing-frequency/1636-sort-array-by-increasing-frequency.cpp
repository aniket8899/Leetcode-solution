class Solution {
public:
    static bool cmp(pair<int,int>&a,pair<int,int>&b){

        if(a.second==b.second){
            return a.first>b.first; // print bigger first
        }
        return a.second<b.second;// ascending order
    }
    vector<int> frequencySort(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans;
        unordered_map<int,int>mp;

        for(auto num:nums){
            mp[num]++;
        }

        vector<pair<int,int>>v;
        for(auto it:mp){
            v.push_back(it);
        }
        sort(v.begin(),v.end(),cmp);

        for(auto it:v){
           for(int i=0;i<it.second;i++){
            ans.push_back(it.first);
           }
        }
        return ans;
    }
};