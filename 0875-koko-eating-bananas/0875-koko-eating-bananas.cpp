class Solution {
public:

bool CanKokoFinishingBananaswithSpeed(vector<int>& piles,int h,int k)
{
    long long int Totalhourstakenbykokofinishallbananas=0;
    for(int i=0;i<piles.size();i++){
        Totalhourstakenbykokofinishallbananas+=ceil(piles[i]/(double)k);
        
    }
    return Totalhourstakenbykokofinishallbananas<=h;
}
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int s=1;
        int ans=0;
        int e=*max_element(piles.begin(),piles.end());
        while(s<=e){
            int mid=s+(e-s)/2;
            int k=mid;  
            if(CanKokoFinishingBananaswithSpeed(piles,h,k)){
                //koko will finish all bananaa
                //without being caught
                ans=mid;
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return ans;
        
    }
};