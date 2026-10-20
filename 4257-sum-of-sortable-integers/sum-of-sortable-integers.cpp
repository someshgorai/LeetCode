class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp = nums;
        sort(temp.begin(), temp.end());

        vector<int> divisors;
        for (int i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                divisors.push_back(i);
                if (n / i != i) {
                    divisors.push_back(n/i);
                }
            }
        }

        int sum = 0;
        for (int k : divisors) {
            bool isValid = true;
            for (int i = 0; i < n; i += k) {
                int drop = 0;
                int dropIdx = -1;
                for (int j = i; j < i + k - 1; j++) {
                    if (nums[j] > nums[j+1]) {
                        drop++;
                        dropIdx = j;
                        if (drop > 1) break;
                    }
                }
                if (drop > 1) {
                    isValid = false;
                    break;
                }
                for (int j = 0; j < k; j++) {
                    if (nums[i + (dropIdx + 1 + j) % k] != temp[i + j]) {
                        isValid = false;
                        break;
                    }
                }
                if (!isValid) break;
            }
            if (isValid) {
                cout << k;
                sum += k;
            }
        }


        return sum;
    }
};