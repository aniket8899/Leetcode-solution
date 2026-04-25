class Solution {
public:
    bool validDigit(int n, int x) {
        string str=to_string(n);

        if(str[0]==x+'0'){
            return false;
        }

        if(str.find(x+'0') !=string::npos){
            return true;
        }

        return false;
    }
};