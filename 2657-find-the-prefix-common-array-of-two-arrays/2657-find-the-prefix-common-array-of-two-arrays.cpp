class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int>ans;

        unordered_map<int,int>mp;
        int cnt=0;

        for(int i=0;i<A.size();i++){

            //phala a wala ko map me store karka fir check kar rha h ki 2 ka equal h ya nhi
            mp[A[i]]++;

            if(mp[A[i]]==2){
                cnt++;
            }
            //jab a complete ho jaya tab me b ko map me push karta hu tab check karta h step wise maater karti h 
            mp[B[i]]++;
            if(mp[B[i]]==2){
                cnt++;
            }

            ans.push_back(cnt);
        }

        return ans;


        
    }
};