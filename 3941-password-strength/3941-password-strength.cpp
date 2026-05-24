class Solution {
public:
    int passwordStrength(string password) {
        int totalsum=0;

        int n=password.size();
        map<char,char>mp;

        for(auto num:password){
            mp[num]++;
        }

        for(auto it:mp){

            if(it.first >='a' && it.first <='z'){
                totalsum+=1;
            }else if(it.first >='A' && it.first <='Z'){
                totalsum+=2;
            }else if(it.first >='0' && it.first <='9'){
                totalsum+=3;
            }else{
                totalsum+=5;
            }
        }
        return totalsum;
        
    }
};