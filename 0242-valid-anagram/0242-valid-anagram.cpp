class Solution {
public:
    bool isAnagram(string s, string t) {
    //   int freqTable[256]={0};
    //   for(int i=0;i<s.size();i++){
    //     freqTable[s[i]]++;
    //   }
    //   for(int i=0;i<t.size();i++){
    //      freqTable[t[i]]--;
    //   }
    //   for(int i=0;i<256;i++){
    //     if(freqTable[i]!=0){
    //         return false;
    //     }
    //   }
    //     return true;

    // sort(s.begin(),s.end());
    // sort(t.begin(),t.end());

    // int n=s.size();
    // int m=t.size();
    // if(n!=m) return false;
    //  for(int i=0;i<n && i<m;i++){
    //     if(s[i]!=t[i]){
    //         return false;
    //     }
    //  }
    //  return true;


   unordered_map<char,int>freq;

    for(int i=0;i<s.size();i++){
        freq[s[i]]++;
    }
    for(int i=0;i<t.size();i++){
        freq[t[i]]--;

    }
    for(int i=0;i<256;i++){
        if(freq[i]!=0){
            return false;
        }
    }
    return true;
    }
};