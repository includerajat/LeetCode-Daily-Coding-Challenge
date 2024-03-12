// Let's connect on LinkedIn: aka.ms/includerajat
// LeetCode problem link -> https://leetcode.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list/

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
class Solution
{
public:
  ListNode *removeZeroSumSublists(ListNode *head)
  {
    ListNode *dummy = new ListNode(0);
    dummy->next = head;
    int prefix_sum = 0;
    unordered_map<int, ListNode *> m;
    for (ListNode *node = dummy; node != NULL; node = node->next)
    {
      prefix_sum += node->val;
      m[prefix_sum] = node;
    }
    prefix_sum = 0;
    for (ListNode *node = dummy; node != NULL; node = node->next)
    {
      prefix_sum += node->val;
      node->next = m[prefix_sum]->next;
    }
    return dummy->next;
  }
};