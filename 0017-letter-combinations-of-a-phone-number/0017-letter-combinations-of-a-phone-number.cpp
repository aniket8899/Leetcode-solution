class Solution {
public:

    void solve(string digits,vector<string>&ans,string& output,unordered_map<char,string>&mp,int i){
        //base case
        if(i==digits.size()){
            ans.push_back(output);
            return;
        }

        string mapdigit=mp[digits[i]];

        for(int j=0;j<mapdigit.size();j++){
            output.push_back(mapdigit[j]);

            solve(digits,ans,output,mp,i+1);
            output.pop_back();
        }

       
    }

    vector<string> letterCombinations(string digits) {
         vector<string>ans;
         string output="";
         unordered_map<char,string>mp;
         mp['2']="abc";
         mp['3']="def";
         mp['4']="ghi";
         mp['5']="jkl";
         mp['6']="mno";
         mp['7']="pqrs";
         mp['8']="tuv";
         mp['9']="wxyz";

         solve(digits,ans,output,mp,0);
         return ans;
        
    }
};