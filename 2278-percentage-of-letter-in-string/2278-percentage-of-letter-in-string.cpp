class Solution {
public:
    int percentageLetter(string s, char letter) {
        int n=s.size();

       unordered_map<char,int>mp;
       for(auto ch:s){
        mp[ch]++;
       }
        int cnt=0;
       for(auto it:mp){
        if(it.first==letter){
            cnt=it.second;
        }
       }

       return (cnt*100)/n;
    }
};