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
    ListNode* collisionPoint(ListNode* t1, ListNode* t2, int d){
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
        if(headA==NULL || headB==NULL) return NULL;
        ListNode* tempA=headA;
        ListNode* tempB=headB;
        int n1=0, n2=0;
        while(tempA!=NULL){
            n1++;
            tempA=tempA->next;
        }
        while(tempB!=NULL){
            n2++;
            tempB=tempB->next;
        }
        if(n1<n2){
            return collisionPoint(headA, headB, n2-n1);  //headA is smaller
        }
        else{
            return collisionPoint(headB, headA, n1-n2);
        }
    }
};