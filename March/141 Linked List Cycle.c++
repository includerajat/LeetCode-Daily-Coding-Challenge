// Let's connect on LinkedIn: aka.ms/includerajat
// LeetCode problem link -> https://leetcode.com/problems/linked-list-cycle/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
  bool hasCycle(ListNode *head)
  {
    unordered_set<ListNode *> s;
    while (head != NULL)
    {
      if (s.find(head) != s.end())
        return true;
      s.insert(head);
      head = head->next;
    }
    return false;
  }
};