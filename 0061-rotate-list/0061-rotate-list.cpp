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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next ||k==0) return head;
        ListNode* temp=head;
        vector<int>ans;
        while(temp!=nullptr){
            ans.push_back(temp->val);
            temp=temp->next;
        }
        vector<int>rotated;
        int n=ans.size();
        k%=n;
        if(k==0) return head;
        for(int j=n-k;j<n;j++){
            rotated.push_back(ans[j]);
        }
        for(int i=0;i<n-k;i++){
            rotated.push_back(ans[i]);
        }
        ListNode* newhead=new ListNode(rotated[0]);
        ListNode* curr=newhead;
        for(int i=1;i<n;i++){
            curr->next=new ListNode(rotated[i]);
            curr=curr->next;
        }
        return newhead;
        


        
    }
};