// Let's connect on LinkedIn: aka.ms/includerajat
// LeetCode problem link -> https://leetcode.com/problems/contiguous-array/

class Solution
{
public:
  int findMaxLength(vector<int> &nums)
  {
    unordered_map<int, int> m;
    int pSum = 0;
    int res = 0;
    for (int i = 0; i < nums.size(); i++)
    {
      int val = 1;
      if (nums[i] == 0)
        val = -1;
      pSum += val;
      if (pSum == 0)
        res = i + 1;
      if (m.find(pSum) != m.end())
      {
        res = max(res, i - m[pSum]);
      }
      else
      {
        m[pSum] = i;
      }
    }
    return res;
  }
};