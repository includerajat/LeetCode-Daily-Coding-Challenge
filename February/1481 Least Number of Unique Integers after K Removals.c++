// Let's connect on LinkedIn: aka.ms/includerajat
// LeetCode problem link -> https://leetcode.com/problems/least-number-of-unique-integers-after-k-removals/

class Solution
{
public:
  int findLeastNumOfUniqueInts(vector<int> &arr, int k)
  {
    unordered_map<int, int> m;
    for (int ele : arr)
      m[ele]++;
    vector<int> freq(m.size());
    int i = 0;
    for (auto p : m)
    {
      freq[i++] = p.second;
    }
    sort(freq.begin(), freq.end());
    int rem = arr.size() - k;
    if (rem < 2)
      return rem;
    int ans = 0;
    for (int i = freq.size() - 1; i >= 0; i--)
    {
      ans++;
      rem -= freq[i];
      if (rem <= 0)
        return ans;
    }
    return ans;
  }
};