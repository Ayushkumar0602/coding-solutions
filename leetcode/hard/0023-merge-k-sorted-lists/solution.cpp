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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> traverse;

        // Traverse all linked lists and collect values
        for (int i = 0; i < lists.size(); i++) {
            ListNode* curr = lists[i];
            while (curr) {
                traverse.push_back(curr->val);
                curr = curr->next;
            }
        }

        // If all lists are empty
        if (traverse.empty()) return nullptr;

        // Sort all node values
        sort(traverse.begin(), traverse.end());

        // Build the new linked list from sorted values
        ListNode* head = new ListNode(traverse[0]);
        ListNode* temp = head;

        for (int i = 1; i < traverse.size(); i++) {
            temp->next = new ListNode(traverse[i]);
            temp = temp->next;
        }

        return head;
    }
};
