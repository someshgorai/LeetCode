class Solution {
public:
    typedef long long ll;
    int maximumWidth(vector<int>& planks) {
        unordered_map<ll, int> freq, res;
        
        for (int plank : planks) {
            freq[plank]++;
            res[plank]++;
        }

        for (auto &a : freq) {
            for (auto &b : freq) {
                int p1 = a.first, p2 = b.first;
                int c1 = a.second, c2 = b.second;

                if (p1 < p2) {
                    res[p1 + p2] += min(c1, c2);
                } 
                if (p1 == p2) {
                    res[2*p1] += c1/2;
                }
            }
        }

        int maxWidth = 1;
        for (auto &[h, w] : res) {
            maxWidth = max(maxWidth, w);
        }

        return maxWidth;
    }
};