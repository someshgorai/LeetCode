class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxProfit = 0;
        int maxSell = prices[n-1];
        for (int i = n-2; i >= 0; i--) {
            if (prices[i] > maxSell) {
                maxSell = prices[i];
            }
            else {
                maxProfit = max(maxProfit, maxSell - prices[i]);
            }
        }
        return maxProfit;
    }
};