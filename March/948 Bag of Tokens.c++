// Let's connect on LinkedIn: aka.ms/includerajat
// LeetCode problem link -> https://leetcode.com/problems/bag-of-tokens/

class Solution
{
public:
  int bagOfTokensScore(vector<int> &tokens, int power)
  {
    int start = 0, end = tokens.size() - 1;
    int score = 0;
    int res = 0;
    sort(tokens.begin(), tokens.end());
    while (start <= end)
    {
      if (tokens[start] <= power)
      {
        power -= tokens[start++];
        score++;
      }
      else
      {
        if (score == 0)
          return res;
        power += tokens[end--];
        score--;
      }
      res = max(res, score);
    }
    return res;
  }
};