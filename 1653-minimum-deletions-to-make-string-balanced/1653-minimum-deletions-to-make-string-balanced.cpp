class Solution {
public:
    int minimumDeletions(string s) {
        int cntB=0;
        int ans=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='b'){
                cntB++;
            }
            else{
                ans=min(ans+1,cntB);
            }
        }
        return ans;
        
    }
};