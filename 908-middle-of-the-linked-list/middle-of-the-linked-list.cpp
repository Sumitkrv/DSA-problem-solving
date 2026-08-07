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
    ListNode* middleNode(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode* temp=head;
        int cnt=0;
        while(temp!=NULL){
            cnt++;
            temp=temp->next;
        }
        temp=head;
        int midNode=(cnt/2);
        while(temp!=NULL){
            if(midNode==0){
                return temp;
            }
            midNode--;
            temp=temp->next;

        }
        return temp;
    }
};