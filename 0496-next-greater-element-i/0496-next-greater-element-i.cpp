class Solution {
public:

/*
nums2=1,3,4,2
ans=3,4,-1,-1

nums1=4,1,2
ans=-1,2,-1


*/
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
         

         stack<int>st;

       unordered_map<int,int>mp;

       for(auto num:nums2){
        mp[num]=-1;
       }

       for(int i=m-1;i>=0;i--){
        while(!st.empty() && st.top()<nums2[i]){
            st.pop();
        }

        if(!st.empty()){
            mp[nums2[i]]=st.top();
        }

        st.push(nums2[i]);


       }

       vector<int>ans;

       for(auto nu:nums1){
        ans.push_back(mp[nu]);
       }

       return ans;




    }
};