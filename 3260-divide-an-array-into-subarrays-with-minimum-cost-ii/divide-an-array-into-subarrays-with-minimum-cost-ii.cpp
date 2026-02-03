class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        int n = nums.size();
        set<pair<int, int>> minElements;
        set<pair<int, int>> remaining;
        long long sum = 0;
        int i = 1;
        while (i - dist <= 0) {
            minElements.insert({nums[i], i});
            sum += nums[i];
            if (minElements.size() > k-1) {
                auto temp = *minElements.rbegin();
                remaining.insert(temp);
                minElements.erase(temp);
                sum -= temp.first;
            }
            i++;
        } 
        cout << sum;
        long long res = 1e18;
        while (i < n) {
            // Adding new element
            minElements.insert({nums[i], i});
            sum += nums[i];
            if (minElements.size() > k-1) {
                auto temp = *minElements.rbegin();
                remaining.insert(temp);
                minElements.erase(temp);
                sum -= temp.first;
            }
            res = min(res, sum);
            // removing left
            pair<int, int> remove = {nums[i-dist], i-dist};
            if (minElements.count(remove)) {
                minElements.erase(remove);
                sum -= nums[i-dist];
                if (!remaining.empty()) {
                    auto temp = *remaining.begin();
                    minElements.insert(temp);
                    remaining.erase(temp);
                    sum += temp.first;
                }
            }
            else {
                remaining.erase({nums[i-dist], i-dist});
            }
            
            i++;
        }
        return res + nums[0];
    }
};