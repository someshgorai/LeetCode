class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        return min({
            1LL * cost1 * need1 + 1LL * cost2 * need2,
            1LL * cost1 * max(need1 - need2, 0) + 1LL * costBoth * need2,
            1LL * cost2 * max(need2 - need1, 0) + 1LL * costBoth * need1
        });
    }
};