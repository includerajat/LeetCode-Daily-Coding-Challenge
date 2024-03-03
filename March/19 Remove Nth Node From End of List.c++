// Let's connect on LinkedIn: aka.ms/includerajat
// LeetCode problem link -> https://leetcode.com/problems/remove-nth-node-from-end-of-list/

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
  int listSize(ListNode *head)
  {
    int len = 0;
    while (head != NULL)
    {
      head = head->next;
      len++;
    }
    return len;
  }
  ListNode *removeNthFromEnd(ListNode *head, int n)
  {
    int sz = listSize(head);
    if (n == sz)
    {
      return head->next;
    }
    int travel = sz - n - 1;
    ListNode *node = head;
    while (travel--)
      node = node->next;
    node->next = node->next->next;
    return head;
  }
};