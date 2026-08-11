struct lambda {
    bool operator() (auto &a, auto &b) {
        return a.second < b.second;
    }
};
class Solution {
public:
    typedef pair<char, int> P;
    string frequencySort(string s) {
        unordered_map<char, int> mp;

        for (auto c : s) {
            mp[c]++;
        }

        priority_queue<P, vector<P>, lambda> pq;

        for (auto it : mp) {
            pq.push(it);
        }

        string ans = "";
        while(!pq.empty()) {
            auto [c, freq] = pq.top();
            pq.pop();

            while(freq--) {
                ans += c;
            }
        }

        return ans;
    }
};