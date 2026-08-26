class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {

        int n=s.size();

        int i=0,j=0;
        int cnt=0;
        int ans=0;
        int minlength=INT_MAX;

        while(j<n){
            if(s[j]=='1'){
                cnt++;
            }

            while(cnt>k){
                if(s[i]=='1'){
                    cnt--;
                }

                i++;
            }

            while(cnt==k){
                int len = j - i + 1;

                if (len < minlength ||
                    (len == minlength &&
                     s.substr(i, len) < s.substr(ans, minlength))) {

                    minlength = len;
                    ans = i;
                }

                if(s[i]=='1'){
                    cnt--;
                }

                i++;
                
            }


            j++;


        }

        if(minlength==INT_MAX){
            return "";
        }

        return s.substr(ans,minlength);
        

    }
};