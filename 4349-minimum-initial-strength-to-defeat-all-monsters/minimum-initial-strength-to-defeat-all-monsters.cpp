class Solution {
public:
    typedef long long ll;
    long long minInitialStrength(vector<int>& monsters, vector<vector<int>>& boosts) {
        int n = monsters.size();
        vector<ll> new_boosts(n+1, 0);
        for (auto &boost : boosts) {
            int start = boost[0];
            int end = boost[1];
            ll b = boost[2];
            new_boosts[start] += b;
            new_boosts[end + 1] += -b;
        }

        
        ll ans = 0, prev = 0, bonus = 0;
        for (int i = 0; i < n; i++) {
            bonus += new_boosts[i];
            ll need = monsters[i] - bonus;
            if (need > 0) {
                ans = max(ans, need + prev);
            }
            prev += monsters[i];
        }

        return ans;
    }
};