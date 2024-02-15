// Let's connect on LinkedIn: aka.ms/includerajat
// LeetCode problem link -> https://leetcode.com/problems/find-polygon-with-the-largest-perimeter/

class Solution {
  public long largestPerimeter(int[] nums) {
    Arrays.sort(nums);
    long sum = 0;
    for (int num : nums)
      sum += (long) num;
    for (int i = nums.length - 1; i >= 2; i--) {
      long ele = nums[i];
      sum -= ele;
      if (sum > ele)
        return sum + ele;
    }
    return -1;
  }
}