class Solution {
public:

    // 12 hour =360 degree ghumta h
    // 1hour me= 30 degree aur hour ka sath sath minute bhi badhta h
    // 1 hour=30 degree move karta h
    // 1 minute me 6 degree
    //

    double angleClock(int hour, int minutes) {
        double findhrs=30*hour+ double(0.5*minutes);
         

        double findmin=6*minutes;

        double diff=abs(findmin-findhrs);


     return min(diff,360-diff);

    }
};