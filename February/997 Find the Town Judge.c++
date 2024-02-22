// Let's connect on LinkedIn: aka.ms/includerajat
// LeetCode problem link -> https://leetcode.com/problems/find-the-town-judge/

class Solution
{
public:
  int findJudge(int n, vector<vector<int>> &trust)
  {
    if (n == 1)
      return 1;
    vector<int> help(n + 1, 0);
    unordered_map<int, vector<int>> m;
    for (int i = 0; i < trust.size(); i++)
    {
      help[trust[i][1]]++;
      m[trust[i][0]].push_back(trust[i][1]);
    }
    for (int i = 0; i < help.size(); i++)
    {
      if (help[i] == n - 1)
      {
        if (m.find(i) == m.end())
        {
          return i;
        }
      }
    }
    return -1;
  }
};