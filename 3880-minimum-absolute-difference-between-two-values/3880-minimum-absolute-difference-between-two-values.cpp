class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums) {
        int left=-1;
        int right=-1;

        int mini=INT_MAX;

        for(int i=0;i<nums.size();i++){
            int ele=nums[i];

            if(ele==1) left=i;
            if(ele==2) right=i;

            if(left!=-1 && right!=-1){

            mini=min(mini,abs(left-right));
            }

        }

        if(mini==INT_MAX){
            return -1;
        }
        return mini;
    }
};