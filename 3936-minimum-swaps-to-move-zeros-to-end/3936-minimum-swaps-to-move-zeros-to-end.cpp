class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        // int n=nums.size();
        // int zeros=0;

        // for(int i=0;i<n;i++){
        //     if(nums[i]==0){
        //         zeros++;
        //     }
        // }

        // int swaps=0;

        // int nonzeropart=n-zeros;

        // for(int i=0;i<nonzeropart;i++){
        //     if(nums[i]==0){
        //         swaps++;
        //     }
        // }
        // return swaps;

        int n=nums.size();
        int i=0;
        int j=n-1;
        int cnt=0;

        while(i<j){
            // jab i traverse karnega to 0 to nhi

            while( i<j && nums[i]!=0){
                i++;
            }

            // jab j traverse karenga 
            while(i<j && nums[j]==0){
                j--;
            }

            if(i<j){
                swap(nums[i],nums[j]);
                cnt++;
                i++,j--;
            }
        }
        return cnt;
    }
};