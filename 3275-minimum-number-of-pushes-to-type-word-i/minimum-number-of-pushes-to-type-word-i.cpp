class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        int layers = n/8;
        if (layers == 0) {
            return (n % 8);
        }
        else if (layers == 1) {
            return 8 + (n % 8) * 2;
        }
        else if (layers == 2) {
            return 24 + (n % 8) * 3;
        }
        return 48 + (n % 8)*4;
    }
};