class Solution {
public:

/*
nums=1,2,4,5

cmp=1,2,3,4,5




*/



    vector<int> findMissingElements(vector<int>& nums) {
        vector<int>ans;

        int n=nums.size();

        sort(nums.begin(),nums.end());

        vector<int>cmp;

        int st=nums[0];

        int ed=nums[n-1];

        for(int i=st;i<=ed;i++){
            cmp.push_back(i);
        }

       int i=0;int j=0;

       while(i<n && j<cmp.size()){
        if(nums[i]==cmp[j]){
            i++,j++;
        }else{
            ans.push_back(cmp[j]);
            j++;
        }
       }

        return ans;

    }
};