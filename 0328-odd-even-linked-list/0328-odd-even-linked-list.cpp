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
    ListNode* oddEvenList(ListNode* head) {
        // if(head==NULL) return head;
        // vector<int>ans;
        // ListNode* temp=head;
        
        // while(temp!=NULL && temp->next!=NULL){
        //     ans.push_back(temp->val);
        //     temp=temp->next->next;
        // }
        // if(temp){
        //     ans.push_back(temp->val);
        // }
        //  temp=head->next;

        // while(temp!=NULL && temp->next!=NULL){
        //     ans.push_back(temp->val);
        //     temp=temp->next->next;
        // }
        // if(temp){
        //     ans.push_back(temp->val);
        // }

        // int n=ans.size();
        // temp=head;

        // for(int i=0;i<n;i++){
        //     temp->val=ans[i];
        //     temp=temp->next;
        // }
        // return head;


        // method--2

        if(head==NULL || head->next==NULL) return head;

        ListNode* odd=head;
        ListNode* even=head->next;

        ListNode* evenhead=even;

        while(even!=NULL && even->next!=NULL){
            odd->next=odd->next->next;

            even->next=even->next->next;

            odd=odd->next;
            even=even->next;
        }
        odd->next=evenhead;

        return head;
        
    }
};