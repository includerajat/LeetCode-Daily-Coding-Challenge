// Let's connect on LinkedIn: aka.ms/includerajat
// LeetCode problem link -> https://leetcode.com/problems/sort-characters-by-frequency/

class Solution
{
  int mostChar(int *cm)
  {
    int idx = -1;
    int f = 0;
    for (int i = 0; i < 256; i++)
    {
      if (cm[i] > f)
      {
        f = cm[i];
        idx = i;
      }
    }
    return idx;
  }

public:
  string frequencySort(string s)
  {
    int *cm = new int[256];
    for (int i = 0; i < 256; i++)
      cm[i] = 0;
    int n = s.length();
    for (int i = 0; i < n; i++)
    {
      cm[s[i]]++;
    }
    string res = "";
    int i = 0;
    while (i < n)
    {
      int idx = mostChar(cm);
      int val = cm[idx];
      while (val--)
      {
        res += char(idx);
        i++;
      }
      cm[idx] = 0;
    }
    return res;
  }
};