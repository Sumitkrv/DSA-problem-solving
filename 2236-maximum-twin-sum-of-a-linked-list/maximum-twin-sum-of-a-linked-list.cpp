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
    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        while (head) {
            ListNode* nextNode = head->next;
            head->next = prev;
            prev = head;
            head = nextNode;
        }
        return prev;
    }

    int pairSum(ListNode* head) {
        ListNode *slow = head, *fast = head;

        // Find the middle
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse second half
        ListNode* second = reverse(slow);

        int ans = 0;
        ListNode* first = head;

        // Compute maximum twin sum
        while (second) {
            ans = max(ans, first->val + second->val);
            first = first->next;
            second = second->next;
        }

        return ans;
    }
};