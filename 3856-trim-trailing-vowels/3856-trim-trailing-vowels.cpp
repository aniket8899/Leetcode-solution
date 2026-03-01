class Solution {
public:
    string trimTrailingVowels(string s) {
        int n=s.length();
        for(int i=n-1;i>=0;i--){
            if(s[i]=='a' || s[i]=='e'||s[i]=='o'||s[i]=='i' ||s[i]=='u'){
                s.erase(i,1);
            }
            else{
                break;
            }
        }
        return s;
    }
};