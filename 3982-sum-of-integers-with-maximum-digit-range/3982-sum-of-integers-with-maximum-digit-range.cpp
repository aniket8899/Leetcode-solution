class Solution {
public:
    int solve(string &s){
        int n=s.size();
        int maxi=INT_MIN;
        int mini=INT_MAX;
        int diff=0;

        for(int i=0;i<n;i++){
            maxi=max(maxi,s[i]-'0');
            mini=min(mini,s[i]-'0');

            diff=maxi-mini;

        }
        return diff;
    }
    int maxDigitRange(vector<int>& nums) {

        int n=nums.size();
        int maxi=INT_MIN;
         

        for(int i=0;i<n;i++){
          string s=to_string(nums[i]);

          maxi=max(maxi,solve(s));
        }

        

       int sum=0;
       for(int i=0;i<n;i++){
        string s=to_string(nums[i]);
        int range=solve(s);


        if(range==maxi){
            sum+=nums[i];
        }
       }

       return sum;




        

    }
};