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
    ListNode* reverseList(ListNode* head) {
        if (!head || !(head->next)) {
            return head;
        }
        // new head
        auto node = reverseList(head->next);
        // reverse link prev
        head->next->next = head;
        
        // break link
        head->next = nullptr;
        
        return node;
    }
};