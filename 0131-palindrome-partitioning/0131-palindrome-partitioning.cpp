class Solution {
public:
    bool ispalindrome(string s,int st,int ed){

        while(st<=ed){
            if(s[st]!=s[ed]){
                return false;
            }else{
                st++;
                ed--;
            }
        }
        return true;
    }
    void solve(string s, vector<vector<string>>&ans,vector<string>&ds,int i){
        // base case
        if(i==s.size()){
            ans.push_back(ds);
        }

        for(int j=i;j<s.size();j++){
            if(ispalindrome(s,i,j)){
                ds.push_back(s.substr(i,j-i+1));

                solve(s,ans,ds,j+1);
                ds.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
         vector<vector<string>>ans;
         vector<string>ds;

         solve(s,ans,ds,0);
         return ans;
    }
};