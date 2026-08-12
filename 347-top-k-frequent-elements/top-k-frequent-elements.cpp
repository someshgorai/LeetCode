class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;

        for (int num : nums) {
            mp[num]++;
        }

        int pqSize = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        for (auto &[num, freq] : mp) {
            if (pqSize < k) {
                pq.push({freq, num});
                pqSize++;
            }
            else {
                pq.push({freq,num});
                pq.pop();
            }
        }

        vector<int> res;
        while(!pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
        }

        return res;
    }
};