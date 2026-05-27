class Solution {
public:
    int numberOfSpecialChars(string word) {

    

       map<char,int>mp;

       for(auto it:word){
        mp[it]++;
       }

        int cnt=0;
       for(char ch='a';ch<='z';ch++){
        if(mp.find(ch)!=mp.end()  && mp.find(toupper(ch))!=mp.end()){
                cnt++;
        }
       }

    return cnt;


        
    }
};