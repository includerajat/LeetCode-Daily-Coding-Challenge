// Let's connect on LinkedIn: aka.ms/includerajat
// LeetCode problem link -> https://leetcode.com/problems/reorder-list/

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
  void reorderList(ListNode *head)
  {
    if ((head == NULL) || (head->next == NULL) || (head->next->next) == NULL)
      return;
    stack<ListNode *> st;
    ListNode *ptr = head;
    while (ptr != NULL)
    {
      st.push(ptr);
      ptr = ptr->next;
    }
    int size = st.size();
    ListNode *pptr = head;
    for (int j = 0; j < (size / 2); j++)
    {
      ListNode *ele = st.top();
      st.pop();
      ele->next = pptr->next;
      pptr->next = ele;
      pptr = pptr->next->next;
    }
    pptr->next = NULL;
  }
};