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
        ListNode* prev = nullptr;
        ListNode* node = nullptr;
        
        ListNode* iter = head;
        while (iter != nullptr) {
            node = iter->next;
            iter->next = prev;
            
            prev = iter;
            iter = node;
        }

        return prev;
    }
};