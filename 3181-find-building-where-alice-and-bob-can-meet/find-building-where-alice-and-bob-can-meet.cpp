class Solution {
private:
    void buildTree(int i, int left, int right, vector<int> &st, vector<int> &h) {
        if (left == right) {
            st[i] = left;
            return;
        }

        int mid = (left + right) / 2;
        buildTree(2*i+1, left, mid, st, h);
        buildTree(2*i+2, mid+1, right, st, h);

        int L = st[2*i+1];
        int R = st[2*i+2];
        st[i] = (h[L] >= h[R] ? L : R);
    }

    int queryMaxIdx(int i, int left, int right, int ql, int qr,
                    vector<int> &st, vector<int> &h) {

        if (qr < left || right < ql) return -1;
        if (ql <= left && right <= qr) return st[i];

        int mid = (left + right) / 2;
        int L = queryMaxIdx(2*i+1, left, mid, ql, qr, st, h);
        int R = queryMaxIdx(2*i+2, mid+1, right, ql, qr, st, h);

        if (L == -1) return R;
        if (R == -1) return L;
        return (h[L] >= h[R] ? L : R);
    }

    int meetingPoint(int l, int r, int margin, vector<int> &st, vector<int> &h, int n) {
        int ans = -1;
        while (l <= r) {
            int mid = (l + r) / 2;
            int idx = queryMaxIdx(0, 0, n-1, l, mid, st, h);

            if (idx != -1 && h[idx] > margin) {
                ans = idx;
                r = mid - 1;   // search more left
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }

public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int n = heights.size();
        vector<int> st(4*n);
        buildTree(0, 0, n-1, st, heights);

        vector<int> ans;
        ans.reserve(queries.size());

        for (auto &q : queries) {
            int a = q[0], b = q[1];

            if (a == b) {
                ans.push_back(a);
                continue;
            }

            // normalize so a < b
            if (a > b) swap(a, b);

            // direct meeting at b
            if (heights[a] < heights[b]) {
                ans.push_back(b);
                continue;
            }

            int left = b + 1;
            int margin = max(heights[a], heights[b]);

            if (left >= n) {
                ans.push_back(-1);
                continue;
            }

            ans.push_back(meetingPoint(left, n-1, margin, st, heights, n));
        }

        return ans;
    }
};

