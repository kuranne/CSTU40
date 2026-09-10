#include "stack.h"
#include <cctype>
#include <iostream>
#include <string>

using namespace std;

int isPalindrome(string word) {
  Stack s;

  // TODO 6: Push every letter onto the stack in uppercase.
  for (int i = 0; i < word.length(); i++) {
    if (word[i] >= 97 && word[i] <= 122)
      word[i] -= 32;
    s.push(word[i]);
  }
  // TODO 7: Pop and compare each letter with the original word.
  // Return 0 immediately when two letters are different.
  char c;
  int i = 0;

  while ((c = s.pop()) != '\0') {
    if (c != word[i++])
      return 0;
  }
  return 1;
}

int main() {
  string word;

  // cout << "Enter one word: ";
  cin >> word;

  if (isPalindrome(word)) {
    cout << "Palindrome" << endl;
  } else {
    cout << "Not palindrome" << endl;
  }

  return 0;
}
