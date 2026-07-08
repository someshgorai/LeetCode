class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size() / 2;
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        
        // left[k] stores all possible sums of choosing exactly 'k' elements from the left half
        vector<vector<int>> left(n + 1), right(n + 1);
        
        // Generate all subset sums for the left half using bitmasking
        for (int mask = 0; mask < (1 << n); ++mask) {
            int sz = 0, sum = 0;
            for (int i = 0; i < n; ++i) {
                if (mask & (1 << i)) {
                    sz++;
                    sum += nums[i];
                }
            }
            left[sz].push_back(sum);
        }
        
        // Generate all subset sums for the right half using bitmasking
        for (int mask = 0; mask < (1 << n); ++mask) {
            int sz = 0, sum = 0;
            for (int i = 0; i < n; ++i) {
                if (mask & (1 << i)) {
                    sz++;
                    sum += nums[n + i];
                }
            }
            right[sz].push_back(sum);
        }
        
        // Sort the right half sums so we can use binary search
        for (int k = 0; k <= n; ++k) {
            sort(right[k].begin(), right[k].end());
        }
        
        int minDiff = 1e9; // Initialize with a large number
        int target = totalSum / 2;
        
        // Meet in the middle
        for (int k = 0; k <= n; ++k) {
            // If we take k elements from the left, we need (n - k) elements from the right
            int rightK = n - k; 
            
            for (int leftSum : left[k]) {
                // We want: leftSum + rightSum ≈ totalSum / 2
                // Therefore: rightSum ≈ (totalSum / 2) - leftSum
                int idealRight = target - leftSum;
                
                // Binary search for the closest value in the specific right half bucket
                auto it = lower_bound(right[rightK].begin(), right[rightK].end(), idealRight);
                
                // Check the exact or slightly larger match
                if (it != right[rightK].end()) {
                    int currentSum = leftSum + *it;
                    int otherSum = totalSum - currentSum;
                    minDiff = min(minDiff, abs(currentSum - otherSum));
                }
                
                // Check the slightly smaller match
                if (it != right[rightK].begin()) {
                    auto prevIt = prev(it);
                    int currentSum = leftSum + *prevIt;
                    int otherSum = totalSum - currentSum;
                    minDiff = min(minDiff, abs(currentSum - otherSum));
                }
            }
        }
        
        return minDiff;
    }
};