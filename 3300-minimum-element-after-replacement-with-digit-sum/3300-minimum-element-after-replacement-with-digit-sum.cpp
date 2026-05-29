class Solution {
public:
    int solve(string &s){
        int sum=0;

        for(int i=0;i<s.size();i++){
            sum+=s[i]-'0';
        }
        return sum;
    }
    int minElement(vector<int>& nums) {

        int n=nums.size();
        int mini=INT_MAX;

        for(int i=0;i<n;i++){
            string s=to_string(nums[i]);
            int sum=solve(s);

            mini=min(mini,sum);


        }

        return mini;
        
    }
};