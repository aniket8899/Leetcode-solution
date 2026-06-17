class Solution {
public:
    char processStr(string s, long long k) {

        int n=s.size();

        long long len=0;

        for(int i=0;i<n;i++){
            if(s[i]=='*'){
                if(len>0){
                    len--;
                }
            }else if(s[i]=='#'){
                len*=2;
            }else if(s[i]=='%'){
                continue;
            }else{
                len++;
            }
        }

        if(k>=len) return '.';

        // traverse a reverse

        for(int i=n-1;i>=0;i--){
            if(s[i]=='*'){
                len++;
            }else if(s[i]=='#'){
                len/=2;
                if(k>=len){
                    k=k-len;
                }
            }else if(s[i]=='%'){
                k=len-k-1;
            }else{
                len--;

                if(k==len) return s[i];
            }
        }

        return '.';
        
    }
};