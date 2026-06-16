class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        set<string> st;
        for (string gene : bank) {
            st.insert(gene);
        }
        queue<pair<int, string>> q;

        vector<char> strand = {'A', 'C', 'G', 'T'};
        q.emplace(0, startGene);

        while (!q.empty()) {
            auto [len, gene] = q.front();
            q.pop();

            if (gene == endGene) return len;

            for (int i = 0; i < 8; i++) {
                string temp = gene;
                for (char s : strand) {
                    temp[i] = s;
                    if (st.find(temp) != st.end()) {
                        q.emplace(len + 1, temp);
                        st.erase(temp);
                    }
                }
            }
        }

        return -1;
    }
};