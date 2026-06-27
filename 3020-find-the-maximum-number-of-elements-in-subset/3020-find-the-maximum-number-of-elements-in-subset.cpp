class Solution {
public:

    typedef long long ll;

    // is question me mugha x,x^2,x^4,x^8...... x^k,x^k/2......x^8,x^4,x^2,x aisa pattern find karna h

    // approach sabse phala map me store kar lenga

    // // mugha [key,value] lekin mugha key pe iterate karna h

    // ek case ye bhi dhyan rakhna nums me only 1 aajaya jaisa {1,1,1,1} ye even h answer hoga ek kam
    // odd case {1,1,1} satified the pattern ans 3 hoga length



    int maximumLength(vector<int>& nums) {

        map<ll,int>mp;

        ll result=0;



        for(auto num:nums){
            mp[num]++;
        }
        
        // 1 check karta h

        if(mp[1]%2!=0){ //odd case
            result=mp[1];
        }else {
            result=mp[1]-1; // even case
        }


        for(auto it:mp){
            int curr=it.first;

            if(curr==1){
                continue;
            }
            ll val=curr;
            ll len=0;

            while(mp.find(val)!=mp.end() && mp[val]>1){
                len+=2;
                val=val*val;
            }

            if(mp.find(val)!=mp.end()){
                len+=1; // agar mil gya toh len 1 hoga 
            }else{
                len-=1;
            }

            result=max(result,len);


        }

        return result;
    }
};