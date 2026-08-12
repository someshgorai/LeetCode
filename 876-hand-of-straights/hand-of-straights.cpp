class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int, int> mp;
        for (int i : hand) {
            mp[i]++;
        }

        while(!mp.empty()) {
            int s = mp.begin()->first;
            for (int j = 0; j < groupSize; j++) {
                if (mp.count(s) == 0) return false;
                mp[s]--;
                if (mp[s] == 0) {
                    mp.erase(s);
                }
                s++;
            }
        }

        return true;
    }
};