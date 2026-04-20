class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int n=s.size();
        int ans=0;

        for(int i=0;i<n;i++){
            unordered_set<char>st;
            for(int j=i;j<n;j++){
               if(st.find(s[j])!=st.end()){
                break;
               }

               st.insert(s[j]);

               int len=j-i+1;
               ans=max(ans,len);

        }
        }

        return ans;
        
    }
};