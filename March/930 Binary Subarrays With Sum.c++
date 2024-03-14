// Let's connect on LinkedIn: aka.ms/includerajat
// LeetCode problem link -> https://leetcode.com/problems/binary-subarrays-with-sum/

class Solution
{
public:
  int numSubarraysWithSum(vector<int> &nums, int goal)
  {
    unordered_map<int, int> m;
    m[0]++;
    int preSum = 0;
    int res = 0;
    for (int i = 0; i < nums.size(); i++)
    {
      preSum += nums[i];
      res += m[preSum - goal];
      m[preSum]++;
    }
    return res;
  }
};