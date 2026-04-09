class Solution {
public:

    const int INT_MIN_VAL = -2147483648;
    const int INT_MAX_VAL = 2147483647;

    int solve(string &s,int i,long long j,long long sign){
        // base case
        if(i>=s.size() || !isdigit(s[i])){
            return int(sign*j);
        }

    j=j*10 +(s[i] -'0');

    if(sign*j <=INT_MIN_VAL) return INT_MIN_VAL;

    if(sign* j>=INT_MAX_VAL ) return INT_MAX_VAL;

    return solve(s,i+1,j,sign);






    }
    int myAtoi(string s) {
        
        int i=0;
        while(i<s.size() && s[i]==' ') i++;

        int sign=1;
       if(i < s.size() && (s[i] == '+' || s[i] == '-')){
       sign = (s[i] == '-') ? -1 : 1;
         i++;
}

        return solve(s,i,0,sign); 
    }
};