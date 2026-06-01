class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
       unordered_map<int,int>hash;
       for(int i=0;i<n;i++){
        hash[nums[i]]++;
       }
      for(auto it:hash){
        if(it.second>1){
            return it.first;
        }
      }
       
         return -1;
    }
  
};