class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int n = tokens.size();
        sort(tokens.begin(), tokens.end());
        int i = 0, j = n-1;

        int score = 0;
        int maxScore = 0;
        while (i <= j) {
            if (tokens[i] <= power) {
                score++;
                power -= tokens[i];
                i++;
                maxScore = max(maxScore, score);
            }
            else if (score > 0) {
                score--;
                power += tokens[j];
                j--;
            }
            else break;
        }

        return maxScore;
    }
};