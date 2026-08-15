class Solution {
public:
    int elevatorRequests(int n, vector<int>& requests) {

        int start=requests[0];
        

        for(int i=1;i<requests.size();i++){
        
         start+=abs(requests[i]-requests[i-1]);

            
        }

        cout<<start;

        return start;
        
    }
};