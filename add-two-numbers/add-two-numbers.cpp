class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (!l1 && !l2) {
            return nullptr;
        }
        int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0);
        ListNode* newHead = new ListNode(sum % 10);
        ListNode* next1 = l1 ? l1->next : nullptr;
        
        // add carry
        sum /= 10;
        if (next1) {
            next1->val += sum;
        }
        // no carry, create new node to store value
        else if (sum) {
            next1 = new ListNode(sum);
        }
        // 
        ListNode* next2 = l2 ? l2->next : nullptr;
        newHead->next = addTwoNumbers(next1, next2);
        return newHead;
    }
};