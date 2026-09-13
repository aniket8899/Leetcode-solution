class Solution {
public:
    string removeKdigits(string num, int k) {

        int n=num.size();

        stack<char>st;
        string ans="";

        for(int i=0;i<n;i++){
            while(!st.empty() && st.top()>num[i] && k>0){
                st.pop();
                k--;
                
            }

            cout<<num[i]<<endl;
            

            st.push(num[i]);

            // cout<<st.top()<<endl;

        }


        // agar k is remaining

        while(!st.empty() && k>0){
            st.pop();
            k--;
        }


        

        while(!st.empty()){
            
            ans+=st.top();
            st.pop();
           
            }

            cout<<ans<<endl;

        reverse(ans.begin(),ans.end());


        int i=0;

        while(i<ans.size() && ans[i]=='0'){  // remove leading zero
            i++;
        }

        ans=ans.substr(i);

        if(ans=="") return "0";

        return ans;


        
    }
};