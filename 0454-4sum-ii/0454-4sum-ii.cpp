class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        // int n=nums1.size();
        // int m=nums2.size();
        // int o=nums3.size();
        // int p=nums4.size();
        int cnt=0;

        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         for(int k=0;k<o;k++){
        //             for(int l=0;l<p;l++){
        //                 int sum=nums1[i]+nums2[j]+nums3[k]+nums4[l];
        //                 if(sum==0){
        //                     cnt++;
        //                 }
        //             }
        //         }
        //     }
        // }
        // return cnt;

        unordered_map<int,int>mp;
        // int cnt=0;
       // combine  num1 and nums2
       for(auto a:nums1){
            for(auto b:nums2){
                mp[a+b]++;
            }
       }

       // combine num3 & nums4
       for(auto c:nums3){
        for(auto d:nums4){
            int target=-(c+d);
            if(mp.count(target)){
                cnt+=mp[target];
            }
        }
       }
       return cnt;

    }
};