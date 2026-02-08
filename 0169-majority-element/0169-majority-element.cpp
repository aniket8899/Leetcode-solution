class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
    //     int n=nums.size();
        
    //     unordered_map<int,int>mp;

    //   for(auto num:nums)
    //   {
    //     mp[num]++;
    //   }
    //   for(auto it:mp)
    //   {
    //      if(it.second>n/2)
    //      {
    //         return it.first;
    //      }
    //   }
    //   return -1;
    
    // boyer moore voting algo
    int cnt1=0;
    int ele1=INT_MIN;
    int n=nums.size();

    for(auto x:nums){
        if(x==ele1) cnt1++;
        
        else if(cnt1==0){
            ele1=x;
            cnt1=1;
        }
        
        else{
            cnt1--;
        }
    }
    cnt1=0;
    for(auto x:nums){
        if(x==ele1){
            cnt1++;
        }
        
    }
   
     

    return ele1;
      
    }
};