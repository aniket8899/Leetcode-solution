class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(),asteroids.end());

        int n=asteroids.size();

        long long totalmass=mass;

       for(int i=0;i<asteroids.size();i++){
        if(totalmass>= asteroids[i]){
        totalmass+=asteroids[i];
        }else{
            return false;
        }
           
       }
       return true;
        
    }
};