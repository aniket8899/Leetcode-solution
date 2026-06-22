class Solution {
public:
    int maxNumberOfBalloons(string text) {
        // int n=text.size();
        string temp="balloon";

        unordered_map<char,int>mp;

        for(auto &t:text){
            mp[t]++;
        }
        int mini=INT_MAX;
        int b=mp['b'];
        int a=mp['a'];
        int l=mp['l']/2;
        int o=mp['o']/2;
        int n=mp['n'];

        mini=min({b,a,l,o,n});


        return mini;
        
    }
};