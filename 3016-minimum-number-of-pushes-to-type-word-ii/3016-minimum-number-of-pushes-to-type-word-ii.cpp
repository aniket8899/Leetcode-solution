class Solution {
public:
    static bool cmp(pair<int,int>&a,pair<int,int>&b){
        if(a.second==b.second){
            return  a.first>b.first;
        }

        return a.second>b.second;
    }
    int minimumPushes(string word) {

        unordered_map<char,int>mp;

        int n=word.size();

        for(auto s:word){
            mp[s]++;
        }

        vector<pair<int,int>>v;
        for(auto it:mp){
            v.push_back(it);
        }

        sort(v.begin(),v.end(),cmp);
        int ans=0;
        

       for(int i=0;i<v.size();i++){
        ans+=(i/8+1)*v[i].second;
       }

        return ans;





        
    }
};