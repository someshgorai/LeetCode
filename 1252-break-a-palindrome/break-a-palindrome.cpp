class Solution {
private:
    string getLexiSmaller(string word) {
        int n = word.size();
        int mid = n/2;
        for (int i = 0; i < n; i++) {
            char &c = word[i];

            if (c != 'a') {
                if ((i == mid) && (n & 1)) {
                    continue;
                }
                c = 'a';
                return word;
            }
        }

        word.pop_back();
        word.push_back('b');
        return word;
    }
public:
    string breakPalindrome(string palindrome) {
        int n = palindrome.size();
        if (n == 1) return "";

        string newWord = getLexiSmaller(palindrome);

        return newWord;
    }
};