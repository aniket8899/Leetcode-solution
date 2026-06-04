class Solution {
public:
    int solve(string &s){
        int n=s.size();

       int waviness=0;
    //    int total=0;

       if(n<3){
        return 0;
       }

       for(int i=1;i<n-1;i++){
        // peak
        if(s[i]>s[i-1] && s[i]>s[i+1]){
            waviness+=1;
            // valley
        }else if(s[i-1] >s[i] && s[i+1]>s[i]){
            waviness+=1;
        }
        
       }
       return waviness;
    }
    int totalWaviness(int num1, int num2) {
        // string s1=to_string(num1);
        // string s2=to_string(num2);

        // int waviness=0;
        int ans=0;

        for(int i=num1;i<=num2;i++){
           string s=to_string(i);

         ans+=solve(s);
        }
        return ans;
        
    }
};