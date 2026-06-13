class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        int n=words.size();
        string ans="";

        for(int i=0;i<words.size();i++){
            int sum=0;
            for(int j=0;j<words[i].size();j++){
                sum+=weights[words[i][j]-'a'];
            }
           int modvalue=sum%26;
            int mapped='z'-modvalue;
            ans+=mapped;
        }
        return ans;
        
    }
};