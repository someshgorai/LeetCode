class Solution {
public:
    int getCost(vector<int> nums, int x, int k) {
        int cost = 0;
        for (int i : nums) {
            int r  = i % k;
            int d = abs(x-r);
            cost += min(d, k-d);
        }
        return cost;
    }
public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> even, odd, evenCost(k), oddCost(k);

        for (int i = 0; i < n; i++) {
            if (i & 1) odd.push_back(nums[i]);
            else even.push_back(nums[i]);
        }

        for (int x = 0; x < k; x++) {
            evenCost[x] = getCost(even, x, k);
            oddCost[x] = getCost(odd, x, k);
        }


        int ans = INT_MAX;

        for (int x = 0; x < k; x++) {
            for (int y = 0; y < k; y++) {
                if (x == y) continue;

                ans = min(ans, evenCost[x] + oddCost[y]);
            }
        }

        return ans;
    }
};