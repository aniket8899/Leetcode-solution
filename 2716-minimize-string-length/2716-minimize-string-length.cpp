class Solution {
public:
    int minimizedStringLength(string s) {
        unordered_map<char,int>mp;
        for(auto ch:s){
            mp[ch]++;
        }
        return mp.size();
    }
};