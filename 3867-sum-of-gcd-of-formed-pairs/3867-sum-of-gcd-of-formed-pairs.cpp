class Solution {
public:
    long long gcdSum(vector<int>& nums) {
       long long maxi=INT_MIN;
        vector<long long >prefixgrid;
       for(long long num:nums){
        maxi=max(maxi,num);
        long long temp=gcd(num,maxi);

        prefixgrid.push_back(temp);
       }

       sort(prefixgrid.begin(),prefixgrid.end());

       int st=0;
       int ed=prefixgrid.size()-1;
       long long sum=0;
       while(st<ed){
        long long ans=gcd(prefixgrid[st],prefixgrid[ed]);
        sum+=ans;
        st++,ed--;
       }
        return sum;
    }
};