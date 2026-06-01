class Solution {
public:
    int minimumCost(vector<int>& cost) {

        int n=cost.size();

        long long sum=0;

        sort(cost.begin(),cost.end(),greater<int>());  // descending order


        for(int i=0;i<n;i+=3){
          sum+=cost[i];
          if(i+1 <n){
            sum+=cost[i+1];
          }
        }
        return sum;
        
    }
};