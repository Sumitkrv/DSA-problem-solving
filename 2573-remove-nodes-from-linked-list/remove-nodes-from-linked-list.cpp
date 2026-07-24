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
    ListNode* reverse(ListNode* head){
        ListNode* prev=NULL;
        ListNode* cur=head;
        while(cur){
            ListNode* next=cur->next;
            cur->next=prev;
            prev=cur;
            cur=next;
        }
        return prev;
    }
    ListNode* removeNodes(ListNode* head) {
        head=reverse(head);
        
        int maxi=head->val;
        ListNode* cur=head;
        while(cur && cur->next){
            if(cur->next->val<maxi){
                cur->next=cur->next->next;
            }
            else{
                maxi=cur->next->val;
                
                cur=cur->next;
            }
        }
        return reverse(head);

    }
};