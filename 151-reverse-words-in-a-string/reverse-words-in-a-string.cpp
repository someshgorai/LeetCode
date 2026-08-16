class Solution {
public:
    string reverseWords(string s) {
        vector<string> hold;
        stringstream ss(s);
        string str;

        while(getline(ss, str, ' ')) {
            hold.push_back(str);
        }

        reverse(hold.begin(), hold.end());

        str = "";
        for (string s : hold) {
            if (s.empty()) continue;
            str += s + ' ';
        }

        str.pop_back();
        return str;
    }
};