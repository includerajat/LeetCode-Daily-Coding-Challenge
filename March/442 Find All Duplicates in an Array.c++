// Let's connect on LinkedIn: aka.ms/includerajat
// LeetCode problem link -> https://leetcode.com/problems/find-all-duplicates-in-an-array/

class Solution
{
public:
  vector<int> findDuplicates(vector<int> &nums)
  {
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
      int num = nums[i];
      if (num < 0)
        num = -num;
      if (num > n)
        num -= n;
      int target = nums[num - 1];
      if (target < 0)
      {
        nums[num - 1] -= n;
      }
      else
      {
        nums[num - 1] = -nums[num - 1];
      }
    }
    vector<int> res;
    for (int i = 0; i < n; i++)
    {
      if (abs(nums[i]) > n)
      {
        res.push_back(i + 1);
      }
    }
    return res;
  }
};