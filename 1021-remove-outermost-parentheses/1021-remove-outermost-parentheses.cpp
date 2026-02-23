class Solution {
public:
    string removeOuterParentheses(string s) {
        // string ans="";
        // int level=0;
        // for(int i=0;i<s.length();i++){
        //     char ch=s[i];

        //     if(ch=='('){
        //         if(level>0) ans+=ch;
        //         level++;
        //     }else if(ch==')'){
        //         level--;
        //         if(level>0) ans+=ch;
        //     }
        // }
        // return ans;
        stack<int>st;
       string ans="";
       for(int i=0;i<s.length();i++){
        char ch=s[i];
         if(ch=='('){
            if(!st.empty()){
                ans+=ch;
            }
            st.push(ch);
         }else{
            st.pop();
            if(!st.empty()){
                ans+=ch;
            }
         }
       }
       return ans;
    }
};