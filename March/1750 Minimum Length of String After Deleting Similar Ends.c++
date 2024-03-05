// Let's connect on LinkedIn: aka.ms/includerajat
// LeetCode problem link -> https://leetcode.com/problems/minimum-length-of-string-after-deleting-similar-ends/

class Solution
{
public:
  int minimumLength(string s)
  {
    int start = 0, end = s.length() - 1;
    while (start < end)
    {
      if (s[start] != s[end])
        break;
      char ch1 = s[start];
      while (start <= end && s[start] == ch1)
        start++;
      char ch2 = s[end];
      while (end >= start && s[end] == ch2)
        end--;
      if (start > end)
        return 0;
    }
    return end - start + 1;
  }
};