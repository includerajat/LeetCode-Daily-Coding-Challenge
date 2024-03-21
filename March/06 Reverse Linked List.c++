// Let's connect on LinkedIn: aka.ms/includerajat
// LeetCode problem link -> https://leetcode.com/problems/reverse-linked-list/

class Solution
{
public:
  ListNode *reverseList(ListNode *head)
  {
    ListNode *prev = NULL;
    ListNode *curr = head;
    while (curr != NULL)
    {
      ListNode *next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
    }
    return prev;
  }
};