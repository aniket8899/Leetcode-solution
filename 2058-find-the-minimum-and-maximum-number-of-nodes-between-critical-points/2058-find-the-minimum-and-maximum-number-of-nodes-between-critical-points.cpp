/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int>ans;

        ListNode* temp=head;

        while(temp!=NULL){
            ans.push_back(temp->val);
            temp=temp->next;
        }

        int n=ans.size();
        vector<int>st;

        for(int i=1;i<n-1;i++){
            int curr=ans[i];
            int prev=ans[i-1];
            int next=ans[i+1];

            if(curr > prev && curr>next){
                st.push_back(i);
            }  

            if(curr<prev && curr<next){
                st.push_back(i);
            } 
        }

        // sort(st.begin(),st.end());

        vector<int>as;
        if(st.size()<2){
            return {-1,-1};
        }

        int mini=INT_MAX;
        

        int first=st[0];
        int last=st[st.size()-1];

        int maxi=last-first;



        for(int i=0;i<st.size()-1;i++){  // 2,4,5
                mini=min(mini,abs(st[i+1]-st[i]));
    
        }

        as.push_back(mini);
        as.push_back(maxi);

        return as;
        
    }
};