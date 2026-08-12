class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq(stones.begin(), stones.end());

        while (pq.size() > 1) {
            int large = pq.top();
            pq.pop();

            int secLarge = pq.top();
            pq.pop();

            int diff = large - secLarge;
            if (diff > 0) {
                pq.push(diff);
            }
        }

        return pq.empty() ? 0 : pq.top();
    }
};