class Solution {
private:
    int helper(string s, char ch1, char ch2) {
        int n = s.size();
        int count1 = 0, count2 = 0;
        int maxl = 0;
        unordered_map<int, int> diffMap;
        for (int i = 0; i < n; i++) {
            if (s[i] != ch1 && s[i] != ch2) {
                diffMap.clear();
                count1 = 0;
                count2 = 0;
                continue;
            }

            if (s[i] == ch1) {
                count1++;
            }
            if (s[i] == ch2) {
                count2++;
            }

            if (count1 == count2) {
                maxl = max(maxl, count1 + count2);
            }

            int diff = count2 - count1;
            if (diffMap.count(diff)) {
                maxl = max(maxl, i - diffMap[diff]);
            }
            else {
                diffMap[diff] = i;
            }
        }
        return maxl;
    }
public:
    int longestBalanced(string s) {
        int n = s.size();

        // Case 1
        int count = 1, maxBalenced = 1;
        for (int i = 1; i < n; i++) {
            if (s[i] == s[i-1]) {
                count++;
            }
            else {
                maxBalenced = max(maxBalenced, count);
                count = 1;
            }
        }
        maxBalenced = max(maxBalenced, count);

        // Case 2
        maxBalenced = max(maxBalenced, helper(s, 'a', 'b'));
        maxBalenced = max(maxBalenced, helper(s, 'c', 'b'));
        maxBalenced = max(maxBalenced, helper(s, 'a', 'c'));

        // Case 3
        int countA = 0;
        int countB = 0;
        int countC = 0;
        unordered_map<string, int> diffMap;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'a') countA++;
            if (s[i] == 'b') countB++;
            if (s[i] == 'c') countC++;
            
            if (countA == countB && countA == countC) {
                maxBalenced = max(maxBalenced, countA + countB + countC);
            }

            int diff1 = countA - countB;
            int diff2 = countB - countC;
            string key = to_string(diff1) + '_' + to_string(diff2);
            if (diffMap.count(key)) {
                maxBalenced = max(maxBalenced, i - diffMap[key]);
            }
            else {
                diffMap[key] = i;
            }
        }
        return maxBalenced;
    }
};