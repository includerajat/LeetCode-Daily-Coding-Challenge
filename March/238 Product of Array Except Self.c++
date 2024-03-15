// Let's connect on LinkedIn: aka.ms/includerajat
// LeetCode problem link -> https://leetcode.com/problems/product-of-array-except-self/

class Solution
{
public:
  vector<int> productExceptSelf(vector<int> &nums)
  {
    int n = nums.size();
    vector<int> left(n);
    vector<int> right(n);
    int ans = 1;
    for (int i = 0; i < n; i++)
    {
      left[i] = ans * nums[i];
      // cout << left[i] << " ";
      ans *= nums[i];
    }
    ans = 1;
    for (int i = n - 1; i >= 0; i--)
    {
      right[i] = ans * nums[i];
      // cout << right[i] << " ";
      ans *= nums[i];
    }
    vector<int> res(n);
    for (int i = 0; i < n; i++)
    {
      if (i == 0)
      {
        res[i] = right[i + 1];
      }
      else if (i == n - 1)
      {
        res[i] = left[i - 1];
      }
      else
      {
        res[i] = left[i - 1] * right[i + 1];
      }
    }
    return res;
  }
};