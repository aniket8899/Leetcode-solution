class Solution {
public:
    int largestAltitude(vector<int>& gain) {

        int n=gain.size();

        vector<int>prefixsum(n+1);

        prefixsum[0]=0; // first element push

        for(int i=1;i<=n;i++){
            prefixsum[i]=prefixsum[i-1]+gain[i-1];
        }

        int maxi=INT_MIN;

        for(int i=0;i<prefixsum.size();i++){
            maxi=max(maxi,prefixsum[i]);
        }

        return maxi;

        
    }
};