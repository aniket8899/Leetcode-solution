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

    ListNode* mergesort(ListNode* l1,ListNode* l2){

        ListNode* dummy=new ListNode(-1);
        ListNode* temp=dummy;

       while(l1!=NULL && l2!=NULL){
         if(l1->val <=l2->val){
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
       }
       else{
        temp->next=l2;
       }


return dummy->next;

    }
    ListNode* findmiddle(ListNode* head){

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
    ListNode* sortList(ListNode* head) {
        // Method -1
        // ListNode* temp=head;
        // vector<int>ans;

        // while(temp!=NULL){
        //     ans.push_back(temp->val);
        //     temp=temp->next;
        // }

        // sort(ans.begin(),ans.end());

        // temp=head;
        // for(int i=0;i<ans.size();i++){
        //     temp->val=ans[i];
        //     temp=temp->next;
        // }
        // return head;





        // method -2 merge sort
    // base case
    if(head==NULL || head->next==NULL){
        return head;
    }

    ListNode* middle=findmiddle(head);

    // splits into to parts
    // 4->2->1->3
    //splits left--- 4->2
    // splits right--- 1->3;

    ListNode* right=middle->next;
    middle->next=NULL;
    ListNode* left=head;

    left=sortList(left);// call left part
    right=sortList(right); // right part

    return mergesort(left,right);

    }
};