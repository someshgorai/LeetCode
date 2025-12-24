class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int totalApples = accumulate(apple.begin(), apple.end(), 0);
        sort(capacity.begin(), capacity.end(), greater<int>());
        int boxes = 0;
        for (int i:capacity) {
            totalApples -= i;
            boxes++;
            if (totalApples <= 0) return boxes;
        }
        return -1;
    }
};