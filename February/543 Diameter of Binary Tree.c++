// Let's connect on LinkedIn: aka.ms/includerajat
// LeetCode problem link -> https://leetcode.com/problems/diameter-of-binary-tree/

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
pair<int, int> diameter(TreeNode *root)
{
  if (root == NULL)
    return {0, 0};
  pair<int, int> l = diameter(root->left);
  pair<int, int> r = diameter(root->right);
  int lh = l.second;
  int rh = r.second;
  int ld = l.first;
  int rd = r.first;
  int d = max(lh + rh + 1, max(ld, rd));
  int h = max(lh, rh) + 1;
  return {d, h};
}

class Solution
{
public:
  int diameterOfBinaryTree(TreeNode *root)
  {
    return diameter(root).first - 1;
  }
};