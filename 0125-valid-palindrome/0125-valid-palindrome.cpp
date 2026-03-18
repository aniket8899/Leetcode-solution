class Solution {
public:
    bool isPalindrome(string s) {

        // string ans="";
        // for(auto ch:s){
        //     if(isalnum(ch)){
        //         ans.push_back(tolower(ch));
        //     }
        // }

        // string s1=ans;
        // reverse(ans.begin(),ans.end());

        // return s1==ans;


        int n=s.size();
        int i=0;
        int j=n-1;

        while(i<j){
            if(!isalnum(s[i])){
                i++;
            }

            else if(!isalnum(s[j])){
                j--;
            }

             else if(tolower(s[i])!=tolower(s[j])){
                return false;
            }else{
                i++,j--;
            }
        }
        return true;


        
    }
};