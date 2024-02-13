class Solution {
  public boolean isPalindrome(String word) {
    int s = 0, e = word.length() - 1;
    while (s < e) {
      if (word.charAt(s++) != word.charAt(e--))
        return false;
    }
    return true;
  }

  public String firstPalindrome(String[] words) {
    for (String word : words) {
      if (isPalindrome(word))
        return word;
    }
    return "";
  }
}