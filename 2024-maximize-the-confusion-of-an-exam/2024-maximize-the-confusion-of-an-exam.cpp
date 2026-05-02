class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int n=answerKey.size();
        unordered_map<char,int>mp;

        int l=0,r=0,maxfreq=0,maxlen=0;

        while(r<n){
            mp[answerKey[r]]++;

            maxfreq=max(maxfreq,mp[answerKey[r]]);

            while((r-l+1)-maxfreq>k){
                mp[answerKey[l]]--;
                l++;
            }

            int len=r-l+1;
            maxlen=max(maxlen,len);

            r++;
        }
        return maxlen;
        
    }
};