// Let's connect on LinkedIn: aka.ms/includerajat
// LeetCode problem link -> https://leetcode.com/problems/furthest-building-you-can-reach/

class Solution
{
public:
  int furthestBuilding(vector<int> &heights, int bricks, int ladders)
  {
    int s = heights.size();
    priority_queue<int> p;
    int maxD = 0;
    for (int i = 1; i < s; i++)
    {
      int diff = heights[i] - heights[i - 1];
      if (diff > 0)
      {
        if (bricks < diff && ladders == 0)
          return i - 1;
        else if (bricks < diff)
        {
          if (p.empty())
          {
            ladders--;
          }
          else
          {
            int top = p.top();
            if (top > diff)
            {
              p.pop();
              ladders--;
              bricks += top;
              bricks -= diff;
              p.push(diff);
            }
            else
            {
              ladders--;
            }
          }
        }
        else
        {
          bricks -= diff;
          p.push(diff);
        }
      }
    }
    return s - 1;
  }
};