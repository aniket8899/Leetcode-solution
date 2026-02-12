class Solution {
public:
    int longestBalanced(string s) {
        int n=s.length();
        int maxlength=0;
        for(int i=0;i<n;i++){
            vector<int>freq(26,0);
            for(int j=i;j<n;j++){
                freq[s[j]-'a']++;
                
                int mini=INT_MAX;
                int maxi=INT_MIN;
                for(int k=0;k<26;k++){
                    if(freq[k]>0){
                        mini=min(mini,freq[k]);
                        maxi=max(maxi,freq[k]);
                    }
                }
            if(mini==maxi){
                maxlength=max(maxlength,j-i+1);
            }
            }

        }
        return maxlength;
        
    }
};