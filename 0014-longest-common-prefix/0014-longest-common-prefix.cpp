class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        sort(strs.begin(),strs.end());

        string first=strs[0];
        string last=strs[n-1];

        int minlength=min(first.size(),last.size());
        string ans="";
        for(int i=0;i<minlength;i++){
            if(last[i]==first[i]){
                ans+=first[i];
            }else{
                break;
            }
        }
        return ans;

        
    }
};