// Let's connect on LinkedIn: aka.ms/includerajat
// LeetCode problem link -> https://leetcode.com/problems/squares-of-a-sorted-array/

class Solution
{
public:
  vector<int> sortedSquares(vector<int> &nums)
  {
    int n = nums.size();
    vector<int> res(n);
    int zeroIndex = 0;
    int i = 0;
    for (i = 0; i < n; i++)
    {
      if (nums[i] >= 0)
      {
        zeroIndex = i;
        break;
      }
    }
    if (i == n)
      zeroIndex = n;
    int x = zeroIndex, y = x - 1;
    int size = 0;
    while (x < n || y >= 0)
    {
      if (x == n)
      {
        res[size++] = nums[y] * nums[y--];
      }
      else if (y == -1)
      {
        res[size++] = nums[x] * nums[x++];
      }
      else
      {
        if (abs(nums[x]) > abs(nums[y]))
        {
          res[size++] = nums[y] * nums[y--];
        }
        else
        {
          res[size++] = nums[x] * nums[x++];
        }
      }
    }
    return res;
  }
};