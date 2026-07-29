class Solution {
private:
    using ll = long long;

    ll nCr(int n, int r, ll lim) {
        if (r > n) return 0;
        r = min(r, n - r);

        __int128 res = 1;
        for (int i = 1; i <= r; i++) {
            res = res * (n - r + i) / i;
            if (res >= lim) return lim;
        }
        return (ll)res;
    }

    string getKthPalindrome(vector<int> &cnt, ll k, int len) {
        string ans;
        int rem = len;

        for (int pos = 0; pos < len; pos++) {
            for (int c = 0; c < 26; c++) {
                if (cnt[c] == 0) continue;

                cnt[c]--;

                ll ways = 1;
                int left = rem - 1;

                for (int i = 0; i < 26; i++) {
                    if (cnt[i] == 0) continue;

                    ll x = nCr(left, cnt[i], k);

                    if (ways >= k || x >= k || ways > k / x) {
                        ways = k;
                        break;
                    }

                    ways *= x;
                    left -= cnt[i];
                }

                if (ways >= k) {
                    ans.push_back(char('a' + c));
                    rem--;
                    break;
                }

                cnt[c]++;
                k -= ways;
            }
        }

        return ans.size() == len ? ans : "";
    }

public:
    string smallestPalindrome(string s, int k) {
        int n = s.size();
        int len = n / 2;

        vector<int> cnt(26);
        for (int i = 0; i < len; i++)
            cnt[s[i] - 'a']++;

        ll total = 1;
        int left = len;

        for (int i = 0; i < 26; i++) {
            if (cnt[i] == 0) continue;

            ll x = nCr(left, cnt[i], (ll)k);

            if (total >= k || x >= k || total > (ll)k / x) {
                total = k;
                break;
            }

            total *= x;
            left -= cnt[i];
        }

        if ((ll)k > total) return "";

        string first = getKthPalindrome(cnt, k, len);
        if (first.empty() && len) return "";

        string mid;
        if (n & 1) mid.push_back(s[len]);

        string second = first;
        reverse(second.begin(), second.end());

        return first + mid + second;
    }
};