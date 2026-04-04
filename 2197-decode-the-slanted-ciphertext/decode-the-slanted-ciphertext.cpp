class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        if (rows == 1) return encodedText;
        string decodedText = "";
        int len  = encodedText.size();
        int cols = len / rows;
        for (int i = 0; i <= cols; i++) {
            for (int j = i; j < len; j += cols+1) {
                decodedText += encodedText[j];
            }
        }
        while (!decodedText.empty() && decodedText.back() == ' ') {
            decodedText.pop_back();
        }
        return decodedText;
    }
};