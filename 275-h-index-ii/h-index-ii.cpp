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

        while (low <= high) {
            int mid = (high - low)/2 + low;
            int cited = getCitedPapers(citations, mid);
            cout << cited;

            if (cited >= mid) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return high;
    }
};