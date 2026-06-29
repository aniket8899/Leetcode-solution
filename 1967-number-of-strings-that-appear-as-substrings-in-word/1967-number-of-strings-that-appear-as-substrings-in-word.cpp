class Solution {
public:
    int solve(string &patterns,string &word){
        int n=patterns.size();
        int cnt=0;
        // unordered_map<char,int>mp;

       if(word.find(patterns)!=string::npos){
        cnt++;
       }
       return cnt;
    }
    int numOfStrings(vector<string>& patterns, string word) {

        int n=patterns.size();
        int cnt=0;

        for(int i=0;i<n;i++){
            int ans=solve(patterns[i],word);
            cnt+=ans;
        }

        return  cnt;
        
    }
};