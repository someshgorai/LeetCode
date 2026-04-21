class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        int i = 0, j = n - 1;
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (colors[i] != colors[0])   res = max(res, i);
            if (colors[i] != colors[n-1]) res = max(res, n - i - 1);
        }

        return res;
    }
};