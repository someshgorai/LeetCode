class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> freq;
        for (int i : nums) {
            freq[i]++;
        }

        if (k == 1) {
            int ans = -1;
            for (auto &[m, f] : freq) {
                if (f == 1) {
                    ans = max(ans, m);
                }
            }

            return ans;
        }

        if (k == n) {
            return *max_element(nums.begin(), nums.end());
        }

        int head = nums.front();
        int tail = nums.back();


        if (freq[head] == 1 && freq[tail] == 1) return max(head, tail);
        
        if (freq[head] != 1 && freq[tail] == 1) return tail;
        if (freq[head] == 1 && freq[tail] != 1) return head;
        return -1;
    }
};