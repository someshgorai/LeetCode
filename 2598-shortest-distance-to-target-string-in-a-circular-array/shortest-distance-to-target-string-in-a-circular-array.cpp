class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();
        int shortestDistance = 101;

        for (int i = 0; i < n; i++) {
            if (words[i] == target) {
                int d = abs(i - startIndex);
                shortestDistance = min(shortestDistance, min(d, n - d));
            }
        }

        return shortestDistance==101 ? -1 : shortestDistance;
    }
};