class Solution {
public:
    int lengthOfLongestSubstring(string s) {

    //     int n=s.size();

    // int maxlen=0;
    // for(int i=0;i<n;i++){
    //     int hashmap[256]={0};
    //     for(int j=i;j<n;j++){
    //         if(hashmap[s[j]]==1){
    //             break;
    //         }
    //         int len=j-i+1;
    //         maxlen=max(maxlen,len);

    //         hashmap[s[j]]=1;
    //     }
    // }

    // return maxlen;


    // sliding window

    int n=s.size();

    int hashmap[256];

    for(int i=0;i<256;i++){
        hashmap[i]=-1;
    }

    int l=0,r=0,maxlen=0;

    while(r<n){
        //check already map me toh nhi h

        if(hashmap[s[r]]!=-1){
            if(hashmap[s[r]]>=l){
                l=hashmap[s[r]]+1;
            }
        }

        int len=r-l+1;

        maxlen=max(maxlen,len);

        hashmap[s[r]]=r;

        r++;
    }






return maxlen;























        // int ans=0;

        // for(int i=0;i<n;i++){
        //     unordered_set<char>st;
        //     for(int j=i;j<n;j++){
        //        if(st.find(s[j])!=st.end()){
        //         break;
        //        }

        //        st.insert(s[j]);

        //        int len=j-i+1;
        //        ans=max(ans,len);

        // }
        // }

        // return ans;
        
    }
};