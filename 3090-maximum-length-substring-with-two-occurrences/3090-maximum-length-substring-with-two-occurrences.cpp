class Solution {
public:

    /*
    s=bcbbbcba
    substring
     b          c
     bc         cb
     bcb        cbb
     bcbb
     bcbbb
     bcbbbc
     bcbbbcb
     bcbbbcba

    
    
    
    */





    int maximumLengthSubstring(string s) {

        int n=s.size();
        // int len=0;

        // for(int i=0;i<n;i++){
        //     unordered_map<int,int>mp;
        //     for(int j=i;j<n;j++){

        //         mp[s[j]]++;

        //         if(mp[s[j]]>2){
        //           break;
        //         }

        //         len=max(len,j-i+1);




        //     }
        //     mp.clear();
        // }

        // return len;

        int i=0,j=0,len=0;

        unordered_map<int,int>mp;


        while(j<n){
            mp[s[j]]++;

            while(mp[s[j]]>2){
                mp[s[i]]--;
                i++;
            }

            len=max(len,j-i+1);

            j++;

        }

        return len;
        
    }
};