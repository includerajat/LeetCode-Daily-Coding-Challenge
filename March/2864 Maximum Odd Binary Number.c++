// Let's connect on LinkedIn: aka.ms/includerajat
// LeetCode problem link -> https://leetcode.com/problems/maximum-odd-binary-number/

class Solution
{
public:
  string maximumOddBinaryNumber(string s)
  {
    int oneId = 0;
    int lastOne = 0;
    for (int i = 0; i < s.length(); i++)
    {
      if (s[i] == '1')
      {
        lastOne = oneId;
        swap(s[oneId++], s[i]);
      }
    }
    swap(s[lastOne], s[s.length() - 1]);
    return s;
  }
};