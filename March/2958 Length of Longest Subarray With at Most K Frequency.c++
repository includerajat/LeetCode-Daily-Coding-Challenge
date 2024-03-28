class Solution
{
public:
  int maxSubarrayLength(vector<int> &nums, int k)
  {
    unordered_map<int, int> m;
    int start = 0;
    int i = 0, n = nums.size();
    int res = 1;
    while (i < n)
    {
      m[nums[i]]++;
      if (m[nums[i]] > k)
      {
        res = max(res, i - start);
        while (start < i && nums[start] != nums[i])
        {
          m[nums[start]]--;
          start++;
        }
        m[nums[start]]--;
        start++;
      }
      i++;
    }
    res = max(res, i - start);
    return res;
  }
};