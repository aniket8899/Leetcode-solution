class Solution {
public:
    bool consecutiveSetBits(int n) {

        string ans="";

        while(n!=0){
            char rem=(n%2)+'0';
            ans+=rem;

            n/=2;
        }

        reverse(ans.begin(),ans.end());

        int x=ans.size();

        // string s=to_string(ans);


        int cnt=0;
        for(int i=0;i<x-1;i++){
            if(ans[i]=='1' && ans[i+1]=='1'){
               cnt++;
            }
        }
        return cnt==1;
        
    }
};