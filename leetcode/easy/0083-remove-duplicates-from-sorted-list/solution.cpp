class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL)
            return NULL;

        ListNode* temp = head;

        while (temp != NULL && temp->next != NULL) {
            if (temp->val == temp->next->val) {
                ListNode* dup = temp->next;
                temp->next = temp->next->next;
                delete dup;   
            } else {
                temp = temp->next;
            }
        }

        return head;
    }
};