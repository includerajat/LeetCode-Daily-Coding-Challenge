// Let's connect on LinkedIn: aka.ms/includerajat
// LeetCode problem link -> https://leetcode.com/problems/task-scheduler/

class Solution
{
public:
  int leastInterval(vector<char> &tasks, int n)
  {
    vector<int> cmap(26, 0);
    int maxFreq = 0;
    for (char task : tasks)
    {
      cmap[task - 'A']++;
      maxFreq = max(maxFreq, cmap[task - 'A']);
    }
    int ans = (n + 1) * (maxFreq - 1);
    for (int i = 0; i < 26; i++)
    {
      if (cmap[i] == maxFreq)
        ans++;
    }
    return max((int)tasks.size(), ans);
  }
};