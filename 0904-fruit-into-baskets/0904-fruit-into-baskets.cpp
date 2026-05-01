class Solution {
public:
    int totalFruit(vector<int>& fruits) {

        //brute force
        // int n=fruits.size();

        // int maxlen=0;

        // for(int i=0;i<n;i++){
        //     set<int>st;

        //     for(int j=i;j<n;j++){
        //         st.insert(fruits[j]);

        //         if(st.size()<=2){
        //             int len=j-i+1;
        //             maxlen=max(maxlen,len);
        //         }else{
        //             break;
        //         }
        //     }
        // }

        // return maxlen;

        // two pointer

        int n=fruits.size();

        int l=0,r=0,maxlen=0;

        unordered_map<int ,int>mp;

        while(r<n){
            mp[fruits[r]]++;

            if(mp.size()> 2){
                while(mp.size()>2){
                    mp[fruits[l]]--;

                    if(mp[fruits[l]]==0){
                        mp.erase(fruits[l]);
                    }
                    l++;

                }
            }

            if(mp.size()<=2){
                int len=r-l+1;

                maxlen=max(maxlen,len);
            }
            r++;

        }

        return maxlen;


        
    }
};