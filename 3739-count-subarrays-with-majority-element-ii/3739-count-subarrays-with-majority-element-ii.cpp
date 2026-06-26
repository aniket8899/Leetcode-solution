class Solution {
public:
    typedef long long ll;

   // [1,2,2,3] ----> transform [-1,1,1,-1]  {jab target ka euqal ho toh usa +1 kara nhi toh -1}

//     [-1,1,1,-1]  ---> ssum---  -1,
//     [-1,1,1,-1]  ---> ssum---  -1+1=0,
//     [-1,1,1,-1]  ---> ssum---  0+1=1,
//     [-1,1,1,-1]  ---> ssum---  -1+1=0,

 /// cummsum=[-1,0,1,0]
                               




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


            mp[cummsum]+=1; // map me store kareta rhenga
            result+=validleftpoints; // result me valid ans add karta rhnega

        }

        return result;
    }
};