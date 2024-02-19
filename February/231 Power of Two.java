// Let's connect on LinkedIn: aka.ms/includerajat
// LeetCode problem link -> https://leetcode.com/problems/power-of-two/

class Solution {
  public boolean isPowerOfTwo(int n) {
    return (n <= 0) ? false : (n & n - 1) == 0;
  }
}