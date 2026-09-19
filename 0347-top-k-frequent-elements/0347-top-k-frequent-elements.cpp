class Solution {
public:

    /*
    
     1->3
     2->2
     3->1


    
    */
    vector<int> topKFrequent(vector<int>& nums, int k) {

        vector<int>ans;
        
        unordered_map<int,int>mp;

        priority_queue<pair<int,int>>pq;

        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }

        for(auto it:mp){
            pq.push({it.second,it.first});
        }

        while(k!=0){
            auto top=pq.top();
            ans.push_back(top.second);
            pq.pop();
            k--;
        }



        return ans;

        

    }
};