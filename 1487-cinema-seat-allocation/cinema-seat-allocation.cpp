class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, unordered_set<int>> res;
        for (auto &seat : reservedSeats) {
            res[seat[0]].insert(seat[1]);
        }

        int unRes = n - res.size();
        int grps = unRes * 2;

        for (auto &[row, cols] : res) {
            bool grp1 = true, grp2 = true, grp3 = true;

            for (int col : cols) {
                if (!grp1 && !grp2 && !grp3) break;
                if (col >= 2 && col <= 5) grp1 = false;
                if (col >= 4 && col <= 7) grp2 = false;
                if (col >= 6 && col <= 9) grp3 = false;
            }
            if (grp1 && grp3)
                grps += 2;
            else if (grp1 || grp2 || grp3)
                grps += 1;
        }

        return grps;
    }
};