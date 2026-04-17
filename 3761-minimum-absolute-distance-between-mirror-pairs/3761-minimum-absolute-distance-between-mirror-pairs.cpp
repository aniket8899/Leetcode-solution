class Solution {
public:
    int reversenum(int n){
        int sum=0;
        while(n){
            int rem=n%10;
            sum=sum*10+rem;
            n/=10;
        }
        return sum;
    }
    int minMirrorPairDistance(vector<int>& nums) {
        int n=nums.size();
        map<int,int>mp;
        int ans=INT_MAX;

        
        for(int i=0;i<n;i++){
            
           

            if(mp.find(nums[i])!=mp.end()){

             ans=min(ans,i-mp[nums[i]]);
        }
            mp[reversenum(nums[i])]=i;

        }
       

       if(ans==INT_MAX){
        return -1;
       }else{

       return ans;
       }


        
        
    }
};