class Solution {
public:
    int hammingWeight(int n) {
        string ans="";
        while(n!=0){
            int bit=n%2;
            ans.push_back(bit+'0');
            n/=2;
        }
        reverse(ans.begin(),ans.end());

        int k=ans.length();
        int cnt=0;
        for(int i=0;i<k;i++){
            if(ans[i]=='1'){
                cnt++;
            }
        }
        return cnt;
    }
};