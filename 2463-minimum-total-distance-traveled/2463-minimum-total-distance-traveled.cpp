class Solution {
public:

#define ll long long

    ll solve(int i,int j,vector<int>&robot,vector<int>&position, vector<vector<long long>>&dp){
        // base case
        if(i==robot.size()){
            return 0;
        }

        if(j==position.size()){
            return 1e15;
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        // pick
        ll pick=abs(robot[i]-position[j]) +solve(i+1,j+1,robot,position,dp);

        // unpick
        ll unpick=solve(i,j+1,robot,position,dp);

        return dp[i][j] =min(pick,unpick);


    }

    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        
        sort(robot.begin(),robot.end());

        sort(factory.begin(),factory.end());

       vector<int>position;

   for(auto it:factory){
     int pos=it[0];
     int limit=it[1];


     for(int i=0;i<limit;i++){
        position.push_back(pos);
     }
   }

int n=robot.size();
int m=position.size();
  vector<vector<long long>>dp(n+1,vector<long long>(m+1,-1));
   return solve(0,0,robot,position,dp);




    }
};