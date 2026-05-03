class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length()!=goal.length())
        {
            return false;
        }

        string doubles=s+s;

        return doubles.find(goal)!=string::npos;

        // for(int i=0;i<s.length();i++){
        //     s=s.substr(1)+s[0];
        //     if(s==goal) return true;
        // }
        // return false;

       
    }
};