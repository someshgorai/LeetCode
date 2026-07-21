class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int ones = count(s.begin(), s.end(), '1');
        string t = "1" + s + "1";

        int cnt = 0, zeros = 0, maxConv = 0;
        for (char i : t) {
            if (i == '0') cnt++;

            if (i == '1') {
                if (zeros != 0 && cnt != 0) {
                    maxConv = max(zeros + cnt, maxConv);
                    zeros = cnt;
                    cnt = 0;
                }
                else if (cnt != 0){
                    zeros = cnt;
                    cnt = 0;
                }
            }
        }
        cout << maxConv;
        return maxConv + ones;
    }
};