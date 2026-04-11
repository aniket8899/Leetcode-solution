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
    ListNode* mergeNodes(ListNode* head) {
       ListNode* temp=head;
       vector<int>ans;

       while(temp!=NULL){
        ans.push_back(temp->val);
        temp=temp->next;
       }

    int sum=0;
    int k=0;
    vector<int>result;
      for(int i=0;i<ans.size();i++){
        if(ans[i]!=0){
            sum+=ans[i];
        }else{
            if(sum!=0){
                result.push_back(sum);
                sum=0;
            }
        }
      }


       temp=head->next;
       ListNode* prev=NULL;
      

       for(int i=0;i<result.size();i++){
        temp->val=result[i];
        prev=temp;
        temp=temp->next;
        
       }
       prev->next=NULL;

       return head->next;




      


      
        
    }
};