// Let's connect on LinkedIn: aka.ms/includerajat
// LeetCode problem link -> https://leetcode.com/problems/count-elements-with-maximum-frequency/

class Solution
{
public:
  int maxFrequencyElements(vector<int> &nums)
  {
    unordered_map<int, int> m;
    int maxFreq = 1;
    for (int num : nums)
    {
      m[num]++;
      maxFreq = max(maxFreq, m[num]);
    }
    int res = 0;
    for (auto p : m)
    {
      if (p.second == maxFreq)
        res += p.second;
    }
    return res;
  }
};