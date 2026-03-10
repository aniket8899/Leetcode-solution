class Solution {
public:
    int maxDepth(string s) {
        int count=0;
        int maxcount=INT_MIN;

        for(auto ch:s){
            if(ch=='('){
                count++;
            }else if(ch==')'){
                count--;
            }
            maxcount=max(maxcount,count);
        }
        return maxcount;
    }
};