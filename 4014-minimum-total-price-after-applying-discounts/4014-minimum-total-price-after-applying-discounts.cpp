class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        
        sort(prices.begin(),prices.end());

        sort(discounts.begin(),discounts.end());

        int n=prices.size();

        int m=discounts.size();

        int i=n-1;
        int j=m-1;

         double sum=0;
        

        while( i>=0 && j>=0 ){
            double ans= (double)prices[i] * (double)(100-discounts[j])/100;

           sum+=ans;

            i--,j--;
        }

       

       while(i>=0){
        sum+=prices[i];
        i--;
       }

        return sum;
    }
};