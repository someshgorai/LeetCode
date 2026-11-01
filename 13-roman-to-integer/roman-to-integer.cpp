class Solution {
public:
    int romanToInt(string s) {
        int n = s.size();
        unordered_map<char, int> mp;
        mp['I'] = 1;
        mp['V'] = 5;
        mp['X'] = 10;
        mp['L'] = 50;
        mp['C'] = 100;
        mp['D'] = 500;
        mp['M'] = 1000;

        int alt = 0;
        int sum = 0;
        for (int i = n-1; i >= 0; i--) {
            if (i != n-1 && mp[s[i]] < mp[s[i + 1]]) {
                alt = -1;
            }
            else alt = 1;

            sum += alt * mp[s[i]];
        }

        return sum;
    }
};