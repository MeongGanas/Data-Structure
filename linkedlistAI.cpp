class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == NULL || head->next == NULL) {
            return false;
        }

        ListNode *slow = head;
        ListNode *fast = head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;          // Bergerak 1 langkah
            fast = fast->next->next;    // Bergerak 2 langkah

            // Jika bertemu, berarti ada siklus
            if (slow == fast) {
                return true;
            }
        }

        return false;
    }
};