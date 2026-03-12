class Solution {
public:
    bool isIsomorphic(string s, string t) {
        // int hash[256]={0};
        // int isthashmapped[256]={0};
        // for(int i=0;i<s.size();i++){
        //     if(hash[s[i]]==0&&isthashmapped[t[i]]==0){
        //         hash[s[i]]=t[i];
        //         isthashmapped[t[i]]=true;
        //     }
        // }
        // for(int i=0;i<s.size();i++){
        //     if(char(hash[s[i]])!=t[i]){
        //         return false;
        //     }
        // }
        // return true;


        int m1[256]={0};
        int m2[256]={0};

        for(int i=0;i<s.size();i++){
            if(m1[s[i]]!=m2[t[i]]) return false;

            m1[s[i]]=i+1;
            m2[t[i]]=i+1;
        }
        return true;
    }
};