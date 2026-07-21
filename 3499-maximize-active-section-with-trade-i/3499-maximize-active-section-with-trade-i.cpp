class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {

        int n=s.size();

        

        vector<int>zerocnt;
        int cnt=0;

        int cntone=0;

        for(auto str:s){
            if(str=='1'){
                cntone++;
            }
        }

        for(int i=0;i<n;i++){
            if(s[i]=='0'){
                cnt++;
                
            }else{

                if(cnt>0){
                    zerocnt.push_back(cnt);
                cnt=0;
                }
            }
        }

        if(cnt>0){
           zerocnt.push_back(cnt); 
        }

        int maxi=0;

        for(int i=1;i<zerocnt.size();i++){
            int sum=zerocnt[i]+zerocnt[i-1];

            maxi=max(maxi,sum);
        }

        return maxi+cntone;
        
    }
};