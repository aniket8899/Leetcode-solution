class Solution {
public:
    int numberOfSpecialChars(string word) {
        //sabse phala lastindex and firstindex stroe kar lenge vector me;
        vector<int>lastindex(26,-1);
        vector<int>firstindex(26,-1);

        int n=word.size();

        for(int i=0;i<n;i++){
            char ch=word[i];
            //to check element lower to h
            if(islower(ch)){
                //tab ham lastindex me store karenga
                lastindex[ch-'a']=i;
            }else{
                // first index like capital lettor

                if(firstindex[ch-'A']==-1){ // o check firstindex me phala -1 toh h
                    firstindex[ch-'A']=i;
                }
            }
        }

        int cnt=0;
        // vetor me sara value stroe karna ka baad check karenga jo phala element lastindex < firstindex se
        for(int i=0;i<26;i++){
            if(lastindex[i]!=-1 && firstindex[i]!=-1 && lastindex[i] <firstindex[i]){
                cnt++;
            }
        }
        return cnt;
    }
};