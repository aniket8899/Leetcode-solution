class Solution {
public:
    string largestOddNumber(string s) {
        int n=s.length();
        int index=-1;
        for(int i=n-1;i>=0;i--){
            if((s[i]-'0')%2==1){
                index=i;
                break;
            }
        }

        int i=0;
        // agar first index pe zero hai toh remove karo
        while(i<=index && s[i]=='0'){
            i++;
        }
        return s.substr(i,index-i+1);
    }
};