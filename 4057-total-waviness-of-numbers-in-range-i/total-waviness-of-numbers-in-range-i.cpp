class Solution {
private:
    int getWave(int num) {
        int prev = num%10;
        num = num/10;
        if (num == 0) return 0;

        int curr = num%10;
        num = num/10;
        if (num == 0) return 0;

        int next = num%10;

        int wave = 0;
        while(num) {
            num = num/10;
            if (prev > curr && curr < next) wave++;
            else if (prev < curr && curr > next) wave++;
            prev = curr;
            curr = next;
            next = num%10;
        }

        return wave;
    }
public:
    int totalWaviness(int num1, int num2) {
        int waveiness = 0;
        for (int i = num1; i <= num2; i++) {
            waveiness += getWave(i);
        }
        return waveiness;
    }
};