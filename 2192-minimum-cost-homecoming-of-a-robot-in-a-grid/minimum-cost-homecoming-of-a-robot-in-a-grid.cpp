class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos,
                vector<int>& rowCosts, vector<int>& colCosts) {

        int sRow = startPos[0], sCol = startPos[1];
        int eRow = homePos[0], eCol = homePos[1];
        int start, end;
        int cost = 0;

        if (sRow < eRow) {
            for (int i = sRow + 1; i <= eRow; i++) cost += rowCosts[i];
        } else {
            for (int i = eRow; i < sRow; i++) cost += rowCosts[i];
        }

        if (sCol < eCol) {
            for (int i = sCol + 1; i <= eCol; i++) cost += colCosts[i];
        } else {
            for (int i = eCol; i < sCol; i++) cost += colCosts[i];
        }

        return cost;
    }
};