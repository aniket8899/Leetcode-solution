class Solution {
public:
    int solve(vector<int>&weights,int capacity){
        int days=1;
        int loads=0;
        for(int i=0;i<weights.size();i++){
            if(loads+weights[i]>capacity){
                days=days+1;
                loads=weights[i];
            }else{
                loads+=weights[i];
            }
        }
        return days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int maxi=*max_element(weights.begin(),weights.end());
        int totalsum=0;
        for(int i=0;i<weights.size();i++){
            totalsum+=weights[i];
        }
        int st=maxi;
        int ed=totalsum;
        int ans=ed;

        while(st<=ed){
            int mid=(st+ed)/2;

            if(solve(weights,mid)<=days){
                ans=mid;
                ed=mid-1;
            }else{
                st=mid+1;
            }
        }
        return ans;
    }
};