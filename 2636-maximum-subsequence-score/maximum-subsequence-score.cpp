class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        vector<pair<int, int>> nums;
        for (int i = 0; i < n; i++) {
            nums.push_back({nums2[i], nums1[i]});
        }

        sort(nums.begin(), nums.end(), greater<>());
        priority_queue<int, vector<int>, greater<int>> pq;
        long long sum = 0;
        long long maxScore = 0;

        for (int i = 0; i < k; i++) {
            pq.push(nums[i].second);
            sum += nums[i].second;
        }

        maxScore = sum * nums[k-1].first;

        for (int i = k; i < n; i++) {
            int minEle = pq.top();

            auto [n2, n1] = nums[i];
            if (minEle < n1) {
                sum += -minEle + n1;
                pq.pop();
                pq.push(n1);
            }   

            maxScore = max(maxScore, sum * n2);
        }

        return maxScore;
    }
};