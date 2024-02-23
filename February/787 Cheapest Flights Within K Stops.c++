// Let's connect on LinkedIn: aka.ms/includerajat
// LeetCode problem link -> https://leetcode.com/problems/cheapest-flights-within-k-stops/

class Solution
{
public:
  int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
  {
    vector<vector<pair<int, int>>> graph(n);
    for (auto route : flights)
    {
      graph[route[0]].push_back({route[1], route[2]});
    }
    vector<int> dist(n, INT_MAX);
    dist[src] = 0;
    queue<pair<int, int>> q;
    q.push({src, 0});
    int stops = 0;
    while (!q.empty() && stops <= k)
    {
      int size = q.size();
      while (size--)
      {
        auto p = q.front();
        q.pop();
        for (auto ele : graph[p.first])
        {
          if (p.second + ele.second >= dist[ele.first])
            continue;
          dist[ele.first] = p.second + ele.second;
          q.push({ele.first, dist[ele.first]});
        }
      }
      stops++;
    }
    return dist[dst] == INT_MAX ? -1 : dist[dst];
  }
};