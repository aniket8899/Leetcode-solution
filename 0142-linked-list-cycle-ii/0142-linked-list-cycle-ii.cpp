/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* cycledetect(ListNode* head){
        ListNode* slow=head;
        ListNode* fast=head;

        while(fast!=NULL){
            fast=fast->next;

            if(fast!=NULL){
                slow=slow->next;
                fast=fast->next;


                if(slow==fast){
                    return slow;
                }
            }
        }
        return NULL;
    }
    ListNode *detectCycle(ListNode *head) {
        // ListNode* temp=head;

        // // if(head!=NULL && head->next!=NULL){
        // //     return head;
        // // }

        // map<ListNode*,int>mp;
        // while(temp!=NULL){
        //     if(mp.find(temp)!=mp.end()){
        //         return temp;
        //     }

        //     mp[temp]=1;
        //     temp=temp->next;
        // }
        // return NULL;


        ListNode* fast=cycledetect(head);
        if(!fast ) return NULL;

        ListNode* slow=head;

        while(slow!=fast){
            slow=slow->next;
            fast=fast->next;
        }
        return slow;
        
    }
};