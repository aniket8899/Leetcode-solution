class Solution {
public:
    int digitFrequencyScore(int n) {

        string s=to_string(n);

        map<char,int>mp;

        for(char ch:s){
            mp[ch]++;
        }

        int sum=0;
        for(auto it:mp){
            sum+=(it.first-'0') *it.second;
        }

        return sum;
        
    }
};