class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {

        int n=arr.size();

        set<int>temp;
        for(int i=0;i<n;i++){
            temp.insert(arr[i]);
        }
        unordered_map<int,int>mp;
        // sort(temp.begin(),temp.end());

        int cnt=1;

        for(auto it:temp){
            mp[it]=cnt++;
        }

        vector<int>ans;

        for(auto a:arr){
            ans.push_back(mp[a]);
        }

        return ans;




        
    }
};