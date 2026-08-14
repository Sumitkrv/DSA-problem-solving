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
    ListNode* findKthNode(ListNode* head, int k){
        k--;
        while(head!=NULL && k>0){
            head=head->next;
            k--;
        }
        return head;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL) return head;
        ListNode* tail=head;
        int len=1;
        while(tail->next!=NULL){
            len++;
            tail=tail->next;
        }
        if(k%len==0) return head;
        k=k%len; 
        tail->next=head;
        ListNode* kthNode=findKthNode(head, len-k);
        ListNode* newHead=kthNode->next;
        kthNode->next=NULL;
        return newHead;

    }
};