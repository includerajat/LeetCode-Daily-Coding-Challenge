// Let's connect on LinkedIn: aka.ms/includerajat
// LeetCode problem link -> https://leetcode.com/problems/insert-interval/

class Solution
{
public:
  vector<vector<int>> insert(vector<vector<int>> &in, vector<int> &ne)
  {
    bool isMerge = false;
    vector<vector<int>> res;
    for (int i = 0; i < in.size(); i++)
    {
      if (isMerge)
      {
        int size = res.size();
        if (res[size - 1][1] < in[i][0])
          res.push_back(in[i]);
        else
          res[size - 1][1] = max(res[size - 1][1], in[i][1]);
        continue;
      }
      if (in[i][0] > ne[1])
      {
        res.push_back(ne);
        res.push_back(in[i]);
        isMerge = true;
      }
      else if (in[i][1] < ne[0])
      {
        res.push_back(in[i]);
      }
      else
      {
        int left = min(in[i][0], ne[0]);
        int right = max(in[i][1], ne[1]);
        res.push_back({left, right});
        isMerge = true;
      }
    }
    int size = res.size();
    if (size == 0 || res[size - 1][1] < ne[0])
      res.push_back(ne);
    return res;
  }
};