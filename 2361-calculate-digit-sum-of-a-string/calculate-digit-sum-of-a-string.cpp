class Solution {
public:
    string digitSum(string s, int k) {
        string temp = s;
        while (temp.size() > k) {
            string temp1;
            int cnt = 0, sum = 0;
            for (char c : temp) {
                if (cnt == k) {
                    temp1 += to_string(sum);
                    cnt = 0;
                    sum = 0;
                }

                sum += c - '0';
                cnt++;
            } 
            if (cnt != 0) {
                temp1 += to_string(sum);
            }
            temp = temp1;
            cout << temp << endl;
        }

        return temp;
    }
};