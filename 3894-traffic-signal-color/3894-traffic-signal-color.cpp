class Solution {
public:
    string trafficSignal(int timer) {
        // int n=timer.size();
        
       if(timer==0){
            return "Green";
       }else if(timer==30){
            return "Orange";
       }else if(timer>30 && timer<=90){
        return "Red";
       }else{
        return "Invalid";
       }
        
    }
};