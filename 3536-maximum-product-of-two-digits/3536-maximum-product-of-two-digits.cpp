class Solution {
public:
    int maxProduct(int n) {
        string s=to_string(n);

        int m=s.size();

        int maxi=INT_MIN;

        for(int i=0;i<m;i++){
            for(int j=i+1;j<m;j++){
                int ans=(s[i]-'0') * (s[j]-'0');
                // int prod=stoi(s);
                maxi=max(maxi,ans);
            }
        }
        return maxi;
    }
};