class Solution {
public:
    typedef long long ll;
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n=nums.size();

        int cummsum=0;
        ll validleftpoints=0;
        ll result=0;

       unordered_map<int,int>mp;
        mp[0]=1;  //first element push

        //transform

        for(int i=0;i<n;i++){

            if(nums[i]==target){
             validleftpoints+=mp[cummsum]; // mugha phala left element us indics se kaam hua toh usko add karenga
                cummsum+=1;
            }else{
                cummsum-=1;
                 validleftpoints-=mp[cummsum]; // agar nhi hua toh usme se subtract kar denga 
            }


            mp[cummsum]+=1;
            result+=validleftpoints;

        }

        return result;
    }
};