// Let's connect on LinkedIn: aka.ms/includerajat
// LeetCode problem link -> https://leetcode.com/problems/subarray-product-less-than-k/

class Solution
{
public:
  int numSubarrayProductLessThanK(vector<int> &nums, int k)
  {
    int start = 0, n = nums.size();
    while (start < n && nums[start] >= k)
      start++;
    if (start == n)
      return 0;
    int sum = 1;
    int ans = 0;
    for (int i = start; i < n; i++)
    {
      sum *= nums[i];
      if (sum < k)
        continue;
      if (sum >= k)
      {
        ans += (i - start) * (i - start + 1) / 2;
      }
      int temp = start;
      while (temp < n && sum >= k)
      {
        sum /= nums[temp++];
      }
      int diff = i - temp;
      start = temp;
      ans -= diff * (diff + 1) / 2;
    }
    ans += (n - start) * (n - start + 1) / 2;
    return ans;
  }
};