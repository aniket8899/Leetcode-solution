class Solution {
public:
    int solve(string &s){
        int n=s.size();

       int sum=0;


        for(int i=0;i<n;i++){
           int change=s[i]-'0';  // char ko change kar rha h integers
           sum+=change;


        }

        cout<<"sum"<<sum<<endl;

        // int ans=stoi(sum);

        return sum;
    }
    int smallestIndex(vector<int>& nums) {
        int n=nums.size();
        int mini=-1;


        for(int i=0;i<n;i++){

            string s=to_string(nums[i]);

           int ans=solve(s);

           cout<<"ans"<<ans<<endl;

           if(i==ans){

            mini=min(i,ans);

           
           }

           if(i==ans){
            return i;
           }

           cout<<"mini"<<mini<<endl;

        }

       return -1;


    }
};