class Solution {
public:
    void solve(int n,vector<string>&ans, string&out,int i,int j){
        // base case
        if(i+j==2*n){
            ans.push_back(out);
        }

        if(i<n){
            out.push_back('(');
            solve(n,ans,out,i+1,j);
            out.pop_back();
        }

        if(j<i){
            out.push_back(')');
            solve(n,ans,out,i,j+1);
            out.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
         vector<string>ans;
         string out;
         solve(n,ans,out,0,0);
         return ans;
    }
};