// Let's connect on LinkedIn: aka.ms/includerajat
// LeetCode problem link -> https://leetcode.com/problems/merge-in-between-linked-lists/

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
  ListNode *mergeInBetween(ListNode *list1, int a, int b, ListNode *list2)
  {
    ListNode *node = list1;
    b = b - a + 1;
    while (a-- > 1)
    {
      node = node->next;
    }
    ListNode *end = node;
    for (int i = 0; i <= b; i++)
    {
      end = end->next;
    }
    node->next = list2;
    node = node->next;
    while (node->next != NULL)
    {
      node = node->next;
    }
    node->next = end;
    return list1;
  }
};