class Solution {
public:
    bool isAdjacentDiffAtMostTwo(string s) {
        int n=s.size();
        int maxi=INT_MIN;

        for(int i=1;i<n;i++){
            int diff=abs(s[i]-s[i-1]);
             maxi=max(maxi,diff);
        }
       if(maxi<=2){
        return true;
       }
       return false;
    }
};