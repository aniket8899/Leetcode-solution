class Solution {
public:
    int getmax(string s,int k,char ch){
        int n=s.size();

        int i=0,j=0;

        int cnt=0;
        int ans=0;

        while(j<n){

            if(s[j]==ch){
                cnt++;
            }

            while(cnt>k){
                if(s[i]==ch){
                    cnt--;
                }

                i++;
            }

            ans=max(ans,j-i+1);
            j++;
        }

        return ans;
    }
    int maxConsecutiveAnswers(string answerKey, int k) {
        int t=getmax(answerKey,k,'T');
        int f=getmax(answerKey,k,'F');

        return max(t,f);
    }
};