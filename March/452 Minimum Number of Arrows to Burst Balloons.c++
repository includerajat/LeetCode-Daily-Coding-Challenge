// Let's connect on LinkedIn: aka.ms/includerajat
// LeetCode problem link -> https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/

class Solution
{
public:
  bool collapse(pair<int, int> a, pair<int, int> b)
  {
    return (a.first <= b.first && a.second >= b.first) || (a.first <= b.second && a.second >= b.second);
  }
  int findMinArrowShots(vector<vector<int>> &points)
  {
    int size = points.size();
    if (size <= 1)
      return 1;
    sort(points.begin(), points.end());
    int res = 0;
    int i = 0;
    while (i < points.size())
    {
      int start = points[i][0];
      int end = points[i][1];
      while (i < points.size() - 1 && collapse(make_pair(start, end), make_pair(points[i + 1][0], points[i + 1][1])))
      {
        start = max(start, points[i + 1][0]);
        end = min(end, points[i + 1][1]);
        i++;
      }
      i++;
      res++;
    }
    return res;
  }
};