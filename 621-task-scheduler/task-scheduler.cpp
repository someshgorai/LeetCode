class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> mp(26, 0);
        for (char task : tasks) {
            mp[task - 'A']++;
        }

        priority_queue<int> pq;
        for (int freq : mp) {
            if (freq > 0) {
                pq.push(freq);
            }
        }

        int t = 0;
        while (!pq.empty()) {
            vector<int> temp;

            for (int i = 1; i <= n+1; i++) {
                if (!pq.empty()) {
                    int freq = pq.top();
                    pq.pop();
                    freq--;
                    temp.push_back(freq);
                }
            }

            for (int freq : temp) {
                if (freq > 0) {
                    pq.push(freq);
                }
            }

            if (pq.empty()) {
                t += temp.size();
            }
            else {
                t += n+1;
            }
        }

        return t;
    }
};