// Let's connect on LinkedIn: aka.ms/includerajat
// LeetCode problem link -> https://leetcode.com/problems/find-the-duplicate-number/

class Solution
{
public:
  int findDuplicate(vector<int> &nums)
  {
    int point = 0;
    while (nums[point] > 0)
    {
      nums[point] = -nums[point];
      point = -nums[point];
    }
    return point;
  }
};