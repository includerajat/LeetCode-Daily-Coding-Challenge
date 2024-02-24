// Let's connect on LinkedIn: aka.ms/includerajat
// LeetCode problem link -> https://leetcode.com/problems/find-all-people-with-secret/
class Solution
{
public:
  vector<int> findAllPeople(int n, vector<vector<int>> &meetings, int firstPerson)
  {
    vector<vector<pair<int, int>>> graph(n);
    for (auto meeting : meetings)
    {
      graph[meeting[0]].push_back({meeting[1], meeting[2]});
      graph[meeting[1]].push_back({meeting[0], meeting[2]});
    }
    vector<bool> secretKnow(n, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> p;
    p.push({0, 0});
    p.push({0, firstPerson});

    while (!p.empty())
    {
      auto pr = p.top();
      int time = pr.first;
      int person = pr.second;
      p.pop();
      // cout << person << " ";
      if (secretKnow[person])
        continue;
      // cout << person << " ";
      secretKnow[person] = true;

      for (auto meeting : graph[person])
      {
        if (!secretKnow[meeting.first] && meeting.second >= time)
        {
          p.push({meeting.second, meeting.first});
        }
      }
    }
    vector<int> res;
    for (int i = 0; i < n; i++)
    {
      if (secretKnow[i])
        res.push_back(i);
    }
    return res;
  }
};