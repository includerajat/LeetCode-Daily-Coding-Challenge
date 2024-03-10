// Let's connect on LinkedIn: aka.ms/includerajat
// LeetCode problem link -> https://leetcode.com/problems/intersection-of-two-arrays/

class Solution
{
public:
  vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
  {
    unordered_set<int> s1, s2;
    for (int num : nums1)
      s1.insert(num);
    for (int num : nums2)
      s2.insert(num);
    vector<int> res;
    for (auto ele : s1)
    {
      if (s2.find(ele) != s2.end())
        res.push_back(ele);
    }
    return res;
  }
};