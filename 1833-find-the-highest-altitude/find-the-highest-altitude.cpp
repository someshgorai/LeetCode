class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int currAlt = 0;
        int maxAlt = 0;
        for (int g : gain) {
            currAlt += g;
            maxAlt = max(maxAlt, currAlt);
        }
        return maxAlt;
    }
};