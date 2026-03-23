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
    int getlength(ListNode* head){
        ListNode* temp=head;
        int cnt=0;

        while(temp!=NULL){
            cnt++;
            temp=temp->next;
        }
        return cnt;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // ListNode* dummy=new ListNode(-1);
        // dummy->next=head;
        // ListNode*fast=dummy;
        // ListNode*slow=dummy;
        
        // for(int i=0;i<n;i++){
        //     fast=fast->next;

        // }

        // while(fast->next!=NULL){
        //     fast=fast->next;
        //     slow=slow->next;
        // }
        // slow->next=slow->next->next;

        // return dummy->next;

        ListNode* temp=head;
        ListNode* deletenode=NULL;

        int length=getlength(head);
        int result=length-n;

        // n==length
        if(length==n){
            ListNode* temp=head;
            head=head->next;
            delete temp;
            return head;
        }
        while(temp!=NULL){
            result--;

            if(result==0){
                break;
            }
            temp=temp->next;

           
        }
            deletenode=temp->next;

            temp->next=temp->next->next;
         delete deletenode;
        return head;

        
    }
};