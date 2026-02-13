class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n=nums.size();
        
        vector<int>ans;
        unordered_set<int>st(nums.begin(),nums.end());

        for(int i=1;i<=n;i++){
            ans.push_back(i);
        }
        // for(int i=0;i<n;i++){
        //     st.insert(nums[i]);
        // }
        vector<int>result;
        for(auto x:ans){
            if(st.find(x)==st.end()){
                result.push_back(x);
            }
        }
       
        return result;


    }
};