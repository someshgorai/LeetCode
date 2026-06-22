class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int n = *max_element(costs.begin(), costs.end());

        vector<int> freq(n+1, 0);
        for (int i : costs) {
            freq[i]++;
        }

        int count = 0;
        for (int i = 0; i <= n; i++) {
            if (freq[i] == 0) continue;
            int canBuy = min (freq[i], coins/i);
            if (!canBuy) return count;
            coins = coins - canBuy * i;
            count += canBuy;
        }

        return count;
    }
};