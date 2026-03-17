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
    ListNode* mergesort( ListNode* l1, ListNode* l2){
        ListNode* dummy=new ListNode(-1);
        ListNode* temp=dummy;
        
        while(l1!=NULL && l2!=NULL){
            if(l1->val<=l2->val){
                temp->next=l1;
                l1=l1->next;
            }else{
                temp->next=l2;
                l2=l2->next;
            }
            temp=temp->next;
        }
        
        if(l1!=NULL){
            temp->next=l1;
        }else{
            temp->next=l2;
        }
        return dummy->next;
        
    }

    ListNode* findmiddle( ListNode* head){
        if(head==nullptr||head->next==NULL){
            return head;
        }
        
        ListNode* slow=head;
        ListNode* fast=head->next;
        
        while(fast!=NULL){
            fast=fast->next;
            
            if(fast!=NULL){
                slow=slow->next;
                fast=fast->next;
            }
        }
        return slow;
        
    }

    ListNode* insertionSortList(ListNode* head) {
       if(head==nullptr || head->next==NULL){
            return head;
        }
        
        // find middle;
        ListNode* middle=findmiddle(head);
        
        //left part
        ListNode* left=head;
        //right part
        ListNode* right=middle->next;
        middle->next=NULL;  // split kar rha hai
        
        left=insertionSortList(left);
        right=insertionSortList(right);
        
        return mergesort(left,right);


        
    }
};