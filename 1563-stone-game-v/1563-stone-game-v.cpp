class Solution {
public:

/*
 prefixsum build karo 
 6,8,11,15,20,25





*/


int solve(int l,int r,vector<int>&sum,vector<vector<int>>&dp){
    if(l>=r){
        return 0;
    }

    if(dp[l][r]!=-1){
        return dp[l][r];
    }

    int score=0;

    for(int k=l;k<r;k++){ // try k partition
        int leftsum=sum[k];

        if(l>0){
            leftsum-=sum[l-1]; // l->mid
        }

        int rightsum=sum[r]-sum[k]; // mid+1->r


        if(leftsum<rightsum){
            score=max(score,leftsum+solve(l,k,sum,dp));
        }else if(leftsum >rightsum){
            score=max(score,rightsum+solve(k+1,r,sum,dp));
        }else{
            score=max({score,leftsum+solve(l,k,sum,dp),rightsum+solve(k+1,r,sum,dp)});
        }


    }

    return dp[l][r]= score;
}
    int stoneGameV(vector<int>& stoneValue) {

        int n=stoneValue.size();

        vector<vector<int>>dp(n,vector<int>(n,-1));

        vector<int>prefixsum(n);

        prefixsum[0]=stoneValue[0];

        for(int i=1;i<n;i++){
            prefixsum[i]=prefixsum[i-1]+stoneValue[i];
        }

        return solve(0,n-1,prefixsum,dp);


        
    }
};