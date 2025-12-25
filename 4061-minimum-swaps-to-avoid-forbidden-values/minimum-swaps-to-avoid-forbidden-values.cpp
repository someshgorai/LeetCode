class Solution {
public:
    int minSwaps(vector<int>& a, vector<int>& f) {
        int cnt = 0, n = a.size(), maxi = 0;
        map<int,int> a_map, f_map, matching;

        for (int i = 0; i < n; i++) {
            if (a[i] == f[i]) {
                cnt += (a[i] == f[i]);
                matching[a[i]]++;
                maxi = max(maxi, matching[a[i]]);
            }
            a_map[a[i]]++; f_map[f[i]]++;
        }

        for (auto& p : a_map) {
            if (p.second > n - f_map[p.first]) return -1;
        }

        return max(maxi, (cnt + 1)/2);
    }
};