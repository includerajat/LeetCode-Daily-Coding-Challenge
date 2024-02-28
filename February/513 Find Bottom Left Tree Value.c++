// Let's connect on LinkedIn: aka.ms/includerajat
// LeetCode problem link -> https://leetcode.com/problems/find-bottom-left-tree-value/

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
  int findBottomLeftValue(TreeNode *root)
  {
    queue<TreeNode *> q;
    q.push(root);
    int res;
    while (!q.empty())
    {
      int size = q.size();
      res = q.front()->val;
      while (size--)
      {
        auto front = q.front();
        q.pop();
        if (front->left != NULL)
          q.push(front->left);
        if (front->right != NULL)
          q.push(front->right);
      }
    }
    return res;
  }
};