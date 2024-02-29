// Let's connect on LinkedIn: aka.ms/includerajat
// LeetCode problem link -> https://leetcode.com/problems/even-odd-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
  bool isEvenOddTree(TreeNode *root)
  {
    queue<TreeNode *> q;
    q.push(root);
    bool odd = true;
    while (!q.empty())
    {
      int size = q.size();
      TreeNode *front = q.front();
      q.pop();
      if (front->left != NULL)
        q.push(front->left);
      if (front->right != NULL)
        q.push(front->right);
      int val = front->val;
      if (odd)
      {
        if (val % 2 == 0)
          return false;
      }
      else
      {
        if (val & 1)
          return false;
      }
      size--;
      while (size--)
      {
        TreeNode *front = q.front();
        q.pop();
        if (front->left != NULL)
          q.push(front->left);
        if (front->right != NULL)
          q.push(front->right);
        int val1 = front->val;
        if (odd)
        {
          if (val1 % 2 == 0 || val >= val1)
            return false;
        }
        else
        {
          if (val1 & 1 || val <= val1)
            return false;
        }
        val = val1;
      }
      odd = !odd;
    }
    return true;
  }
};