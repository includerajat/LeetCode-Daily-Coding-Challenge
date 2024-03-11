// Let's connect on LinkedIn: aka.ms/includerajat
// LeetCode problem link -> https://leetcode.com/problems/custom-sort-string/

class Solution
{
public:
  string customSortString(string order, string s)
  {
    vector<int> cmap(26, 0);
    for (char ch : s)
      cmap[ch - 'a']++;
    string res = "";
    for (char ch : order)
    {
      while (cmap[ch - 'a']--)
      {
        res += ch;
      }
    }
    for (int i = 0; i < 26; i++)
    {
      if (cmap[i] > 0)
      {
        while (cmap[i]--)
        {
          res += ('a' + i);
        }
      }
    }
    return res;
  }
};