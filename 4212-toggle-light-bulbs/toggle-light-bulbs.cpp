class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        vector<bool> state(101, false);
        for (int i : bulbs) {
            state[i] = !state[i];
        }
        vector<int> ans;
        for (int i = 1; i < 101; i++) {
            if (state[i]) ans.push_back(i);
        }
        return ans;
    }
};