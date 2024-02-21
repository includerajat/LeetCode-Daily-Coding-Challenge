// Let's connect on LinkedIn: aka.ms/includerajat
// LeetCode problem link -> https://leetcode.com/problems/bitwise-and-of-numbers-range/

class Solution {
  public int rangeBitwiseAnd(int left, int right) {
    if (left == right)
      return left;
    int leftMSB = (int) (Math.log(left) / Math.log(2));
    int rightMSB = (int) (Math.log(right) / Math.log(2));
    if (leftMSB != rightMSB)
      return 0;
    int ans = right;
    for (int i = left; i < right; i++) {
      ans = (ans & i);
    }
    return ans;
  }
}