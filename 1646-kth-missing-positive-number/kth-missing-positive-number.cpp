class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int num = k;
        for (int i: arr) {
            if (i <= num) num++;
            else return num;
        }
        return num;
    }
};