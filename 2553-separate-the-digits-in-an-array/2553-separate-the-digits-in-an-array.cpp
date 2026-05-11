class Solution {
public:
    vector<int>solve(string s){
        vector<int>ans;
        int n=s.size();

        for(int i=0;i<n;i++){
            ans.push_back(s[i]-'0');
        }
        return ans;
    }
    vector<int> separateDigits(vector<int>& nums) {
        vector<int>ans;
        int n=nums.size();

        for(int i=0;i<n;i++){
            vector<int>digit=solve(to_string(nums[i]));

            for(auto d:digit){
                ans.push_back(d);
            }
        }
        return ans;
        
    }
};