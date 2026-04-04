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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* temp=head;

        vector<int>ans;

        while(temp!=NULL){
            ans.push_back(temp->val);
            temp=temp->next;
        }

       vector<int>res;
        for(int i=0;i<ans.size();i++){
            int sum=0;

            for(int j=i;j<ans.size();j++){
                sum+=ans[j];

                if(sum==0){
                    i=j;
                    break;
                }
            }
            if(sum!=0){
                res.push_back(ans[i]);
            }
        }
      
      ListNode* dummy=new ListNode(-1);
      ListNode* curr=dummy;

       for(int i=0;i<res.size();i++){
        curr->next=new ListNode(res[i]);
        curr=curr->next;
       }
       return dummy->next;
        
    }
};