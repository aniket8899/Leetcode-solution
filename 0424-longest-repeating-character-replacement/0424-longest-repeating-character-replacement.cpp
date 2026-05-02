class Solution {
public:
    int characterReplacement(string s, int k) {

        // unordered_map<char,int>mp;
        vector<int>mp(26,0);

        int l=0,r=0,maxlen=0,maxfreq=0;

        while(r<s.size()){
            mp[s[r]-'A']++;

            maxfreq=max(maxfreq,mp[s[r]-'A']);

          

            while((r-l+1)-maxfreq > k){  //
                mp[s[l]-'A']--;
                l++;

            }
            int len=r-l+1;

            maxlen=max(maxlen,len);

            r++;
          

        }

        return maxlen;

        
        
    }
};