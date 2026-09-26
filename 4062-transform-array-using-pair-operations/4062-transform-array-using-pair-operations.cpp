class Solution {
public:
    bool canTransform(vector<int>& source, vector<int>& target) {

        long long a1=0,a2=0;

        for(auto s:source){
            a1+=s;
        }

        for(auto t:target){
            a2+=t;
        }

        return (a1==a2);
        
    }
};