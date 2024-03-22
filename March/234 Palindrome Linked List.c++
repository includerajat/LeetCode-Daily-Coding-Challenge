// Let's connect on LinkedIn: aka.ms/includerajat
// LeetCode problem link -> https://leetcode.com/problems/palindrome-linked-list/

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
  ListNode *middle(ListNode *head)
  {
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
      slow = slow->next;
      fast = fast->next->next;
    }
    return slow;
  }
  bool isPalindrome(ListNode *head)
  {
    ListNode *node = middle(head);
    ListNode *curr = reverseList(node);
    while (head != NULL && curr != NULL)
    {
      if (head->val != curr->val)
        return false;
      head = head->next;
      curr = curr->next;
    }
    return true;
  }
};