class Solution {
public:
    int minSwaps(vector<int>& a, vector<int>& f) {
        int n = a.size();
        int cnt = 0, maxi = 0;

        unordered_map<int,int> freqA, freqF, badFreq;

        for (int i = 0; i < n; i++) {
            freqA[a[i]]++;
            freqF[f[i]]++;

            if (a[i] == f[i]) {
                cnt++;
                maxi = max(maxi, ++badFreq[a[i]]);
            }
        }

        // Feasibility check
        for (auto &p : freqA) {
            int val = p.first;
            if (p.second > n - freqF[val]) return -1;
        }

        return max(maxi, (cnt + 1) / 2);
    }
};
