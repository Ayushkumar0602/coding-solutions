# Merge k Sorted Lists

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

You are given an array of `k` linked-lists `lists`, each linked-list is sorted in ascending order.

 *Merge all the linked-lists into one sorted linked-list and return it.* 

 

 **Example 1:** 

```
Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted linked list:
1->1->2->3->4->4->5->6

```

 **Example 2:** 

```
Input: lists = []
Output: []

```

 **Example 3:** 

```
Input: lists = [[]]
Output: []

```

 

 **Constraints:** 

- k == lists.length
- 0 <= k <= 104
- 0 <= lists[i].length <= 500
- -104 <= lists[i][j] <= 104
- lists[i] is sorted in ascending order.
- The sum of lists[i].length will not exceed 104.

## Solution

**Language:** C++  
**Runtime:** 6 ms (beats 30.86%)  
**Memory:** 19.2 MB (beats 14.48%)  
**Submitted:** 2026-10-20T08:02:01.650Z  

```cpp
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

```

---

[View on LeetCode](https://leetcode.com/problems/merge-k-sorted-lists/)