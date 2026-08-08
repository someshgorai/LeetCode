class Solution {
public:
    string breakPalindrome(string palindrome) {
        int n = palindrome.size();
        if (n == 1) return "";
        int mid = n/2;
        string word = palindrome;

        for (int i = 0; i < mid; i++) {
            if (word[i] != 'a') {
                word[i] = 'a';
                return word;
            }
        }

        word[n-1] = 'b';
        return word;
    }
};