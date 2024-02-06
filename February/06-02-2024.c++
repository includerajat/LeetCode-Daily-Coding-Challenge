class Solution
{
public:
  vector<vector<string>> groupAnagrams(vector<string> &strs)
  {
    vector<string> h;
    for (int i = 0; i < strs.size(); i++)
    {
      string s = strs[i];
      sort(s.begin(), s.end());
      string r = "";
      for (int i = 0; i < s.length(); i++)
      {
        r = r + s[i];
      }
      h.push_back(r);
    }
    vector<vector<string>> res;
    for (int i = 0; i < strs.size(); i++)
    {
      bool flag = false;
      for (int j = i - 1; j >= 0; j--)
      {
        if (h[j] == h[i])
        {
          flag = true;
          break;
        }
      }
      if (flag == true)
        continue;
      vector<string> s;
      s.push_back(strs[i]);
      for (int j = i + 1; j < strs.size(); j++)
      {
        if (h[j] == h[i])
        {
          s.push_back(strs[j]);
        }
      }
      res.push_back(s);
    }
    return res;
  }
};