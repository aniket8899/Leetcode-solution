class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n=nums1.size();
        // return true;

        vector<int>nums2(n);

        for(int i=0;i<n;i++){
           nums2[i]=nums1[i];
        }

        int m=nums2.size();

        for(int i=0;i<n;i++){
            if(nums2[i]%2==0 || nums2[i]%2==1){
                return true;
            }
        }

        return false;

    }
};