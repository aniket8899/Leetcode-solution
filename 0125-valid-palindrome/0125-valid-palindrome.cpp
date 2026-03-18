class Solution {
public:
    bool isPalindrome(string s) {

        string ans="";
        for(auto ch:s){
            if(isalnum(ch)){
                ans.push_back(tolower(ch));
            }
        }

        string s1=ans;
        reverse(ans.begin(),ans.end());

        return s1==ans;


        
    }
};