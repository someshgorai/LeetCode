class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int n = nums.size();
        vector<long long> temp(n);
        vector<int> preIdx(n), nxtIdx(n);
        set<pair<long long, int>> pairSum;
        for (int i = 0; i < n; i++) {
            preIdx[i] = i-1;
            nxtIdx[i] = i+1;
            temp[i] = nums[i];
        }
        int badPairs = 0;
        for (int i = 0; i < n-1; i++) {
            if (temp[i] > temp[i+1]) badPairs++;
            pairSum.insert({temp[i] + temp[i+1], i});
        }
        int ops = 0;
        while (badPairs > 0) {
            int first = pairSum.begin()->second;
            int second = nxtIdx[first];
            int first_left = preIdx[first];
            int second_right = nxtIdx[second];
            long long sum = pairSum.begin()->first;

            if (temp[first] > temp[second]) {
                badPairs--;
            }

            if (first_left >= 0) {
                if (temp[first_left] > temp[first] && temp[first_left] <= sum) badPairs--;
                if (temp[first_left] <= temp[first] && temp[first_left] > sum) badPairs++;
            }

            if (second_right < n) {
                if (temp[second_right] < temp[second] && temp[second_right] >= sum) badPairs--;
                if (temp[second_right] >= temp[second] && temp[second_right] < sum) badPairs++;
            }

            pairSum.erase({temp[first] + temp[second], first});
            if (first_left >= 0) {
                pairSum.erase({temp[first] + temp[first_left], first_left});
                pairSum.insert({sum + temp[first_left], first_left});
            }
            if (second_right < n) {
                pairSum.erase({temp[second] + temp[second_right], second});
                pairSum.insert({sum + temp[second_right], first});
                preIdx[second_right] = first;
            }
            nxtIdx[first] = second_right;
            temp[first] += temp[second];
            ops++;
        }
        return ops;
    }
};