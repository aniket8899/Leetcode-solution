class Solution {
public:

 
    
    bool ispossible(int mid,vector<vector<int>>& tasks){
        
        for(auto &t:tasks){
            int first=t[0];
            int second=t[1];

            if(mid < second ){
                return false;
            }else if(mid>= second){
                mid-=first;
            }
        }
        return true;
    }
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(),tasks.end(),[](auto& a,auto& b){
            return (a[1]-a[0]) > (b[1]-b[0]);
        });
        
        int n=tasks.size();
        int minsum=0;

        for(auto &t:tasks){
            int first=t[0];
            int second=t[1];

            minsum+=second;
        }

        int st=0;
        int ed=minsum;
        int ans=0;

        while(st<=ed){
            int mid=st+(ed-st)/2;

            if(ispossible(mid,tasks)){
                ans=mid;
                ed=mid-1;
            }else{
                st=mid+1;
            }
        }
        return ans;
    }
};