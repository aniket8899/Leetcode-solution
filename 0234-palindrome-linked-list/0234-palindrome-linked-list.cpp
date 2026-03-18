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
    ListNode* findmiddle(ListNode* head){
        if(head==NULL || head->next==NULL){
            return head;
        }

        ListNode* slow=head;
        ListNode* fast=head->next;

        while(fast!=NULL){
            fast=fast->next;

            if(fast!=NULL){
                fast=fast->next;
                slow=slow->next;
            }
        }
        return slow;
    }

    ListNode* reversell(ListNode* head){
        if(head==NULL || head->next==NULL){
            return head;
        }

        ListNode* prev=NULL;
        ListNode* curr=head;
        while(curr!=NULL){
            ListNode* forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
        }

        return prev;
        
    }
    bool isPalindrome(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return true;
        }

        ListNode* middle=findmiddle(head);
        ListNode* left=head;
        ListNode* right=middle->next;
        middle->next=NULL;

        ListNode* reverse=reversell(right);

        ListNode* temp1=left;
        ListNode* temp2=reverse;

        while(temp2!=NULL){
            if(temp1->val !=temp2->val){
                return false;
            }else{
                temp1=temp1->next;
                temp2=temp2->next;
            }
        }

    return true;
        
    }
};