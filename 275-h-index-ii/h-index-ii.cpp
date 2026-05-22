class Solution {
private:
    int getCitedPapers(vector<int>& citations, int h) {
        int cited = 0;
        for (int i : citations) {
            if (i >= h) {
                cited++;
            }
        }
        return cited;
    }
public:
    int hIndex(vector<int>& citations) {
        int low = 0, high = *max_element(citations.begin(), citations.end());
        int maxHIndex = 0;

        for (int  i = low; i <= high; i++) {
            int cited = getCitedPapers(citations, i);
            cout << cited;

            if (cited >= i) {
                maxHIndex = max(maxHIndex, i);
            }
            else {
                break;
            }
        }

        return maxHIndex;
    }
};