class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int sumodd=0;
        int sumeven=0;

        while(n--){
            int stodd=1;
            int steven=2;
            sumodd+=stodd;

            sumeven+=steven;

            stodd+=2;
            steven+=2;
        }

        return gcd(sumodd,sumeven);

        
        
    }
};