class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {

        unordered_set<string>st; //repeat string na aaya

        // phir mena kya kiya arr1 ko phala string banaka set ka andar insert karenga 
        // 100->>> 1,10,100 --> string me tor ka uska upeer traverse karka set ka andar insert karenga

        for(auto &x:arr1){
            string s=to_string(x);
            string ans="";

            for(auto &temp:s){
                ans+=temp;

                st.insert(ans);
            }
        }

        // phir me kya karunga ki arr22 ko har index pe jaka usko string me change karka 
        // set ka andar count karenga kitna lenght ka persent h

        int maxlength=0;
        for(auto &y:arr2){
            string s=to_string(y);

            string ans="";

            for(auto &temp:s){
                ans+=temp;

                if(st.count(ans)){
                    maxlength=max(maxlength,(int)ans.size());
                }
            }
        }

        return maxlength;



        
    }
};