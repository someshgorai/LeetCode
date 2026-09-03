class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> diff(n, 0);

        for (auto& shift : shifts) {
            if (shift[2] == 0) {
                diff[shift[0]] -= 1;
                if (shift[1] + 1 < n) diff[shift[1] + 1] += 1; 
            }
            else {
                diff[shift[0]] += 1;
                if (shift[1] + 1 < n) diff[shift[1] + 1] -= 1;
            }
        }

        for (int i = 1; i < n; i++) {
            diff[i] = diff[i] + diff[i-1];
        }

        int mod = 26;
        string temp = s;
        for (int i = 0; i < n; i++) {
            int shift;

            if (diff[i] < 0) shift = ((diff[i] % mod) + mod) % mod;
            else shift = diff[i] % mod;

            int change = ((temp[i] - 'a') + shift) % mod;

            temp[i] = 'a' + change;
        }

        return temp;
    }
};