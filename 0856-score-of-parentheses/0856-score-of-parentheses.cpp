class Solution {
public:
    int scoreOfParentheses(string s) {
        
        int cnt=0;
        int score=0;

        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                score++;
            }else{
                score--;

                if(s[i-1]=='('){
                    cnt=cnt+pow(2,score);
                }
            }
        }
        return cnt;
    }
};