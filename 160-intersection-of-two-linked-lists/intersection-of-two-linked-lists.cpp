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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_map<ListNode*, int> mp;
        ListNode* tempA=headA;
        ListNode* tempB=headB;
        if(headA==headB) return headA;
        if(headA==NULL ) return NULL;
        if(headB==NULL ) return NULL;
        while(tempA!=NULL){
            mp[tempA]++;
            tempA=tempA->next;
        }
        while(tempB!=NULL){
            mp[tempB]++;
            if(mp[tempB]>1){
                return tempB;
            }
            tempB=tempB->next;
        }
        return NULL;
    }
};