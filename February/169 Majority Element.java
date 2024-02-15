// Let's connect on LinkedIn: aka.ms/includerajat
// LeetCode problem link -> https://leetcode.com/problems/majority-element/

class Solution {
    public int majorityElement(int[] nums) {
        int majId = 0;
        int count = 1;
        for (int i = 1; i < nums.length; i++) {
            if (nums[i] == nums[majId])
                count++;
            else
                count--;
            if (count == 0) {
                majId = i;
                count = 1;
            }
        }
        return nums[majId];
    }
}
