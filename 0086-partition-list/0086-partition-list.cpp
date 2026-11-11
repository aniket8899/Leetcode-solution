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
    ListNode* partition(ListNode* head, int x) {
        ListNode* small = new ListNode(-1);
        ListNode* large = new ListNode(-1);
        // yaha small and large ko a and b mai isliye address store karege kyu ki dono ko
        // aage badha rhe hai isliye
        ListNode* a = small;
        ListNode* b = large;

        ListNode* curr = head;
        while(curr != NULL){
            if(curr->val < x){
                // small insert
                small->next = new ListNode(curr->val);
                small = small->next;
            }else{
                // large insert
                large->next = new ListNode(curr->val);
                large = large->next;
            }
            curr = curr->next;
        }

        // in a and b we have first -1 so 
        a = a->next;
        b = b->next;

        ListNode* finalans = new ListNode(-1);
        // yaha finalans return nhi karege kyu ki finalans ko move kar rhe hai isliye
        ListNode* ans = finalans;

        while(a != nullptr){
            finalans->next = new ListNode(a->val);
            finalans = finalans->next;
            a = a->next;
        }
        
        while(b != nullptr){
            finalans->next = new ListNode(b->val);
            finalans = finalans->next;
            b = b->next;
        }

        return ans->next;

    }
};