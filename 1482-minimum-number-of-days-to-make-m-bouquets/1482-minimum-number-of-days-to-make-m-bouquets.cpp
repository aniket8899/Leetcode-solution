class Solution {
public:
    bool ispossible(vector<int>&arr,int day,int m,int k){
        int cnt=0;
        int totalbloom=0;
        for(int i=0;i<arr.size();i++){
        if(arr[i]<=day){
            cnt++;
        }else{
            totalbloom+=(cnt/k);
            cnt=0;
        }

        }
        totalbloom+=(cnt/k);

        if(totalbloom>=m){
            return true;
        }else{
            return false;
        }
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        long long val=m*1LL*k*1LL;
        if(val>n) return -1;

        int mini=*min_element(bloomDay.begin(),bloomDay.end());
        int maxi=*max_element(bloomDay.begin(),bloomDay.end());
         int st=mini;
         int ed=maxi;
         int ans=ed;
         while(st<=ed){
            int mid=st+(ed-st)/2;
            if(ispossible(bloomDay,mid,m,k)){
                ans=mid;
                ed=mid-1;
            }else{
                st=mid+1;
            }
         }
         return ans;
    }
};