class Solution {
public:
    bool judgeCircle(string moves) {
        int y = 0, x = 0;
        for (char d : moves) {
            if (d == 'U') y++;
            else if (d == 'D') y--;
            else if (d == 'R') x++;
            else x--;
        }
        return x == 0 && y == 0;
    }
};