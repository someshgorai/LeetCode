class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxSell = prices[n-1];
        int maxProfit = 0;
        for (int i = n - 2; i >= 0; i--) {
            maxProfit = max(maxProfit, maxSell - prices[i]);
            maxSell = max(maxSell, prices[i]);
        }

        return maxProfit;
    }
};