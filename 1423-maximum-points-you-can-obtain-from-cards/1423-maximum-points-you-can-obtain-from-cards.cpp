class Solution {
public:
/*
first traverse leftsum 1,3,6

right sum





*/
    int maxScore(vector<int>& cardPoints, int k) {

        int n=cardPoints.size();
        
        vector<int>leftsum(k+1,0);

        vector<int>rightsum(k+1,0);

        int maxi=INT_MIN;

        // leftsum[0]=cardPoints[0];

        for(int i=1;i<=k;i++){
            leftsum[i]=leftsum[i-1]+cardPoints[i-1];
         cout<<"leftsum"<<leftsum[i]<<endl;
        }

        // 0,100,140,157


        // rightsum[0]=cardPoints[n];

        for(int i=1;i<=k;i++){
            rightsum[i]=rightsum[i-1]+cardPoints[n-i];

          cout<<"rightsum"<<rightsum[i]<<endl;
        }

        // 0,75,148,157


        for(int i=0;i<=k;i++){
            int right=k-i;

            cout<<"right"<<right<<endl;

            int sum=leftsum[i]+rightsum[right];

            cout<<"sum"<<sum<<endl;

            if(sum>maxi){
                maxi=sum;;
            }
        }

        return maxi;


    }

};