class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // unordered_map<int,vector<int>>mp;
       
        // for(int i=0;i<nums.size();i++){
        //     int number = nums[i];
        //     int currval = target - number;
        //     //we found value so 1
        //     if(mp.count(currval) == 1){
        //         return {i,mp[currval]};
        //     }
        //     mp[number] = i;
        // }
        // return{};

    // method--->>2

    // for(int i=0;i<nums.size();i++)
    // {
    //     int val=nums[i];
    //     mp[val].push_back(i);
    // }

    // for(int i=0;i<nums.size();i++)
    // {
    //     int current=nums[i];
    //     int req=target-current;

    //     if(mp.find(req) !=mp.end())
    //     {
    //         if(req==current && mp[current].size()==1)
    //         {
    //             continue;
    //         }

    //         if(req==current && mp[current].size()>1)
    //         {
    //             return {mp[current][0],mp[current][1]};
    //         }
    //         else
    //         {
    //             return {i,mp[req][0]};
    //         }
    //     }
    // }
    // return {};
    int n=nums.size();
  vector<pair<int,int>>mp;
   for(int i=0;i<n;i++){
        mp.push_back({nums[i],i});
   }
   sort(mp.begin(),mp.end());
  
    int left=0,right=n-1;
    
    

    while(left<right){
        int sum=mp[left].first+mp[right].first;
        if(sum==target){
            return {mp[left].second,mp[right].second};
          
        }
        else if(sum<target){
            left++;
        }else{
            right--;
        }
    }
    return {};

    }
};