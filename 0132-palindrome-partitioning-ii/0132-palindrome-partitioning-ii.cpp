class Solution {
public:
    bool ispalindrome(string &s,int st,int ed){
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
    int solve(string&s,int i,vector<int>&dp){
        // base case
        if(i==s.size() || ispalindrome(s,i,s.size()-1)){
            return 0;
        }

        if(dp[i]!=-1){
            return dp[i];
        }

        int mincuts=INT_MAX;

        for(int j=i;j<s.size();j++){
            if(ispalindrome(s,i,j)){
                int cuts=1+solve(s,j+1,dp);
                mincuts=min(mincuts,cuts);
            }
        }
        return dp[i]= mincuts;
    }
    int minCut(string s) {
        int n=s.size();
        vector<int>dp(n+1,-1);
        return solve(s,0,dp);
        
    }
};