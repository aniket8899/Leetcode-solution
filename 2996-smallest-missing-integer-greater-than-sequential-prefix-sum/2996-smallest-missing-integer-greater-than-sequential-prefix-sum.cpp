class Solution {
public:

/*
 nums=1,2,3,2,5

 i=1=num[i-1]+1=1+1=2
 i=2=nums[i-1]+1=3
 i=3=



*/
    int missingInteger(vector<int>& nums) {
        int n=nums.size();

       

        int sum=nums[0];

        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1]+1){
                sum+=nums[i];
            }else{
                break;
            }
        }
        

        unordered_set<int>st;

        for(auto &nu:nums){
            st.insert(nu);
        }

        while(st.count(sum)){
            sum++;
        }

        return sum;
    }
};