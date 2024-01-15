class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if (head == nullptr) return nullptr;
        ListNode *curr = head;
        ListNode *prev = curr;

        while (curr != nullptr && curr->next != nullptr) {
            if (curr->next->val == curr->val) {
                while (curr->next != nullptr && curr->next->val == curr->val) {
                    if (curr == head) head = curr->next;
                    curr = curr->next;
                }
                if (curr == head) head = curr->next;
                curr = curr->next;
                prev->next = curr;
            } else {
                prev = curr;
                curr = curr->next;
            }
        }
        return head;
    }
};
