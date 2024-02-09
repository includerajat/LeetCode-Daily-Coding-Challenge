class Solution
{
public:
  vector<int> largestDivisibleSubset(vector<int> &nums)
  {
    int l = nums.size();
    vector<int> dp(l, 1);
    vector<int> p(l, 0);
    sort(nums.begin(), nums.end());
    int maxE = 1;
    int maxI = 0;
    for (int i = 1; i < l; i++)
    {
      for (int j = 0; j < i; j++)
      {
        if (nums[i] % nums[j] == 0)
        {
          if (dp[j] + 1 > dp[i])
          {
            p[i] = j;
            dp[i] = dp[j] + 1;
          }
          if (maxE < dp[i])
          {
            maxE = dp[i];
            maxI = i;
          }
        }
      }
    }
    vector<int> res;
    while (maxE--)
    {
      res.push_back(nums[maxI]);
      maxI = p[maxI];
    }
    return res;
  }
};