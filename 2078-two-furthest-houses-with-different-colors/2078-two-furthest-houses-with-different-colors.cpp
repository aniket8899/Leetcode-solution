class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n=colors.size();

        int maxi=INT_MIN;

        for(int i=0;i<n;i++){
           for(int j=0;j<n;j++){

            if(colors[i]!=colors[j]){
            int diff=abs(j-i);
            maxi=max(maxi,diff);

            }
           }
        }
        return maxi;
        
    }
};