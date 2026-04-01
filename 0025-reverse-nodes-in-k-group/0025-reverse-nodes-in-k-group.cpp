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
    ListNode* reverseKGroup(ListNode* head, int k) {

        if(head==NULL || head->next==NULL){
            return head;
        }

        int length=getlength(head);

    if(length<k){
        return head;
    }

    ListNode* prev=NULL;
    ListNode* curr=head;

    int pos=0;

    while(pos<k){
        ListNode* forward=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forward;
        pos++;
    }

    if(curr!=NULL){
        ListNode* recu=reverseKGroup(curr,k);
        head->next=recu;
    }
    return prev;
        
    }
};