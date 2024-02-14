class Solution
{
public:
  vector<int> rearrangeArray(vector<int> &nums)
  {
    int n = nums.size(), pos = 0, neg = 1;
    vector<int> res(n);
    for (int num : nums)
    {
      if (num < 0)
        res[neg] = num, neg += 2;
      else
        res[pos] = num, pos += 2;
    }
    return res;
  }
};