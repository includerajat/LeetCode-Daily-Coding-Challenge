// Let's connect on LinkedIn: aka.ms/includerajat
// LeetCode problem link -> https://leetcode.com/problems/first-missing-positive/

class Solution
{
public:
  int firstMissingPositive(vector<int> &nums)
  {
    int n = nums.size();
    int arr[1000000] = {0};
    for (int i = 0; i < n; i++)
    {
      if (nums[i] > 0 and nums[i] <= n)
      {
        arr[nums[i] - 1] = 1;
      }
    }
    for (int i = 0; i < n; i++)
    {
      if (arr[i] == 0)
        return i + 1;
    }
    return n + 1;
  }
};