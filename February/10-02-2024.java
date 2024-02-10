package February;

class Solution {
  static boolean isPalindrome(String s, int i, int j) {
    while (i < j) {
      if (s.charAt(i++) != s.charAt(j--))
        return false;
    }
    return true;
  }

  public int countSubstrings(String s) {
    int l = s.length();
    int ans = 0;
    for (int i = 0; i < l; i++) {
      for (int j = i; j < l; j++) {
        if (isPalindrome(s, i, j))
          ans++;
      }
    }
    return ans;
  }
}
