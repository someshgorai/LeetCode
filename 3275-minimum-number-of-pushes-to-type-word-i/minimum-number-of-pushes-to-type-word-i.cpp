class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        vector<int> index(26, 0);
        
        int layer = 0, press = 0;
        for (char w : word) {
            if (index[w-'a'] == 0) {
                int idx = (layer / 8) + 1;
                index[w-'a'] = idx;
                press += idx;
                layer++;
            }
            else {
                press += index[w - 'a'];
            }
        }

        return press;
    }
};