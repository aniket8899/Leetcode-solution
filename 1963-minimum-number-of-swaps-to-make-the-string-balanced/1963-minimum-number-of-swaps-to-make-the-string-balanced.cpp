class Solution {
public:
    int minSwaps(string s) {
        // stack<char>st;
        // int ans=0;
        // int maxans=0;

        // for(char ch: s)
        // {
        //     if(ch=='[')
        //     {
        //         ans++;
        //         st.push(ch);
                
        //     }
        //     else
        //     {
                
        //        if(!st.empty())
        //        {
        //         ans--;
        //         st.pop();
        //        }
        //        else
        //        {
        //         maxans++;
        //        }
        //     }
        // }
        // return (maxans + 1) /2;


        int ans=0;
        int maxans=0;

        for(auto ch: s)
        {
            if(ch=='[')
          {
            ans++;
          }

          else
          {
            ans--;
            if( ans<0)
            {
                maxans++;
                ans=0;
            }
          }
        }

    return (maxans+1)/2;







    }
};