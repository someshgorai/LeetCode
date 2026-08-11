class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq(piles.begin(), piles.end());

        long long sum = accumulate(piles.begin(), piles.end(), 0LL);

        while(k--) {
            int stones = pq.top();
            int newStones = ceil(stones/2.0);
            pq.pop();
            sum -= (stones - newStones);
            pq.push(newStones);
        }

        return sum;
    }
};