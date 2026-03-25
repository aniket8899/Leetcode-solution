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
    ListNode* collision(ListNode* t1,ListNode* t2,int d){

        while(d){
            d--;
            t2=t2->next;
        }

        while(t1!=t2){
            t1=t1->next;
            t2=t2->next;
        }
        return t1;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        // ListNode* temp=headA;

        // map<ListNode*,int>mp;

        // while(temp!=NULL){
        //     mp[temp]=1;

        //     temp=temp->next;
        // }
        // temp=headB;

        // while(temp!=NULL){
        //     if(mp.find(temp)!=mp.end()){
        //         return temp;
        //     }
        //     temp=temp->next;
        // }
        // return NULL;

        // ListNode* temp=headA;
        // int n1=0;

        // while(temp!=NULL){
        //     n1++;
        //     temp=temp->next;
        // }

        // temp=headB;
        // int n2=0;

        // while(temp!=NULL){
        //     n2++;
        //     temp=temp->next;
        // }

        // if(n1<n2){
        //     return collision(headA,headB,n2-n1);
        // }
        // else{
        //     return collision(headB,headA,n1-n2);
        // }



        if(headA==NULL || headB==NULL) return NULL;

        ListNode* temp1=headA;
        ListNode* temp2=headB;

        while(temp1!=temp2){
            temp1=temp1->next;
            temp2=temp2->next;

            if(temp1==temp2){
                return temp1;
            }

            if(temp1==NULL){
                temp1=headB;
            }

            if(temp2==NULL){
                temp2=headA;
            }
        }
        return temp1;
    }
};