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
    ListNode* middlenode(ListNode*head){
        if(head==NULL || head->next==NULL){
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

    ListNode* reversell(ListNode* head){
        if(head ==NULL || head->next==NULL){
            return head;
        }
        ListNode* curr=head;

        ListNode* prev=NULL;

        while(curr!=NULL){
            ListNode* forward=curr->next;

            curr->next=prev;
            prev=curr;
            curr=forward;
        }
        return prev;
    }
    int pairSum(ListNode* head) {

        ListNode* middle=middlenode(head);

        ListNode* left=head;
        ListNode* right=middle->next;
        middle->next=NULL;

        ListNode* reverse=reversell(right);

        ListNode* temp1=left;
        ListNode* temp2=reverse;
        int maxi=INT_MIN;
        

        while(temp1!=NULL && temp2!=NULL){
            int sum=temp1->val+temp2->val;

            maxi=max(maxi,sum);

            temp1=temp1->next;
            temp2=temp2->next;
        }
        return maxi;
        
    }
};