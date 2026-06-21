class Solution {
public:
    int countValidSubarrays(vector<int>& nums, int x) {

        int n=nums.size();
       
        long long cnt=0;

        for(int i=0;i<n;i++){
                 long long sum=0;
            for(int j=i;j<n;j++){
                sum+=nums[j];

                int last=sum%10; // last digit ka 

                long long first=sum; // 

                while(first>=10){
                    first/=10;
                }

                if(last==x && first==x ){
                    cnt++;
                }
            }
        }

        return cnt;
        
    }
};