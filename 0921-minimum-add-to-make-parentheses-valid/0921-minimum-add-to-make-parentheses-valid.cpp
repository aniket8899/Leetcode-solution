class Solution {
public:
    int minAddToMakeValid(string s) {
        int n=s.size();
        int cnt=0;
        stack<char>st;

        for(int i=0;i<n;i++){
            if(s[i]=='('){
                cnt++;
                st.push(s[i]);
            }else{
                if(!st.empty()){
                    st.pop();
                    cnt--;
                }else{
                    cnt++;
                    
                }
            }
        }
        return cnt;
    }
};