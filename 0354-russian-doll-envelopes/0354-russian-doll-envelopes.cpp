class Solution {
public:
    static bool cmp(vector<int>& a,vector<int>&b){
        if(a[0]==b[0]){
            return a[1]>b[1];  // decreasing
        }
        return a[0]<b[0];  // ascending order
    }

    int solve(vector<int>&ans){
        vector<int>temp;

        temp.push_back(ans[0]);
        for(int i=1;i<ans.size();i++){
            if(ans[i]>temp.back()){
                temp.push_back(ans[i]);
            }else{
                int index=lower_bound(temp.begin(),temp.end(),ans[i])-temp.begin();
                temp[index]=ans[i];
            }
        }

        return temp.size();
    }


    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(),envelopes.end(),cmp);

        vector<int>ans;

        for(auto it:envelopes){
            int wt=it[0];
            int ht=it[1];

            ans.push_back(ht);
        }

        return solve(ans);

    }
};