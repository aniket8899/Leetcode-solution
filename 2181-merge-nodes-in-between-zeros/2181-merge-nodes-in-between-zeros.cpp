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
       for(int i=1;i<ans.size();i++){
          if(ans[i]!=0){
            sum+=ans[i];
          }else{
           result.push_back(sum);
           k++;
            sum=0;
          }
        


       }


      


       int n=result.size();

       ListNode* node = new ListNode(-1);
       ListNode* temps=node;

       for(int j=0;j<k;j++){
        ListNode*  newnode = new ListNode(result[j]);
        temps->next=newnode;
        temps=temps->next;


    
       }
       return node->next;
        
    }
};