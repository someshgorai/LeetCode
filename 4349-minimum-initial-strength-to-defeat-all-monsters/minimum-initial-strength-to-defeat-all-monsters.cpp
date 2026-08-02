class Solution {
    typedef long long ll;
private:
    bool isValid(ll energy, vector<ll> &boosts, vector<int> &monsters) {
        ll boost = 0;
        int n = monsters.size();
        for (int i = 0; i < n; i++) {
            boost += boosts[i];
            if (boost + energy >= monsters[i]) {
                energy = max(energy - monsters[i], 0LL);
            } 
            else return false;
        }

        return true;
    }
public:
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

        
        ll high = accumulate(monsters.begin(), monsters.end(), 0LL);
        ll low = 0;

        while (low <= high) {
            ll mid = (high - low)/2 + low;

            if (isValid(mid, new_boosts, monsters)) high = mid - 1;
            else low = mid + 1;
        }

        return low;
    }
};