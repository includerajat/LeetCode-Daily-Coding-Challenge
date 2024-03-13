// Let's connect on LinkedIn: aka.ms/includerajat
// LeetCode problem link -> https://leetcode.com/problems/find-the-pivot-integer/

class Solution
{
public:
  int pivotInteger(int n)
  {
    int totalSum = n * (n + 1) / 2;
    for (int i = 1; i <= n; i++)
    {
      int sum = i * (i - 1) / 2;
      int leftSum = sum + i;
      int rightSum = totalSum - sum;
      if (leftSum == rightSum)
        return i;
    }
    return -1;
  }
};