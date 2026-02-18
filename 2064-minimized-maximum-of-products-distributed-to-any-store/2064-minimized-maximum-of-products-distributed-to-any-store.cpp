class Solution {
public:
    int solve(vector<int>&arr,int div){
        int sum=0;
        for(int i=0;i<arr.size();i++){
            sum+=ceil((double)arr[i]/div);
        }
        return sum;
    }
    int minimizedMaximum(int n, vector<int>& arr) {
        int st=1;
        int ed=*max_element(arr.begin(),arr.end());

        while(st<=ed){
            int mid=(st+ed)/2;

            if(solve(arr,mid)>n){
                st=mid+1;
            }else{
                ed=mid-1;
            }
        }
        return st;
        
    }
};