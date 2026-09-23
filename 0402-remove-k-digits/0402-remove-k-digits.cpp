class Solution {
public:
    string removeKdigits(string digits, int k) {
        
        int n=digits.size();
        stack<char>st;
        string ans="";

       for(int i=0;i<n;i++){

            while(!st.empty() && st.top()>digits[i] && k>0){
                st.pop();
                k--;
            }

            st.push(digits[i]);
       }

       while(!st.empty() && k>0){
        st.pop();
        k--;
       }

       while(!st.empty()){
        ans+=st.top();
        st.pop();
       }

       reverse(ans.begin(),ans.end());

       int i=0;

       while(i<ans.size() && ans[i]=='0'){
        i++;
       }

       ans=ans.substr(i);

       if(ans=="") return "0";

       return ans;
    }
};