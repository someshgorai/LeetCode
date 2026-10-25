class SORTracker {
public:
    struct cmp1 {
        bool operator()(pair<int, string>& a, pair<int, string>& b) {
            if (a.first == b.first) {
                return a.second < b.second;
            }
            return a.first > b.first; // min-heap
        }
    };

    struct cmp2 {
        bool operator()(pair<int, string>& a, pair<int, string>& b) {
            if (a.first == b.first) {
                return a.second > b.second;
            }
            return a.first < b.first; // max-heap
        }
    };

    int limit = 1;
    int size = 0;
    priority_queue<pair<int, string>, vector<pair<int, string>>, cmp1> bestpq;
    priority_queue<pair<int, string>, vector<pair<int, string>>, cmp2> reserve;
    SORTracker() {
        
    }
    
    void add(string name, int score) {
        bestpq.push({score, name});
        size++;

        if (size > limit) {
            auto res = bestpq.top();
            bestpq.pop();

            reserve.push(res);
            size--;
        }
    }
    
    string get() {
        if (size == 0) return "";

        auto ans = bestpq.top();
        
        limit++;
        if (size < limit && !reserve.empty()) {
            auto res = reserve.top();
            reserve.pop();

            bestpq.push(res);
            size++;
        }

        return ans.second;
    }
};

/**
 * Your SORTracker object will be instantiated and called as such:
 * SORTracker* obj = new SORTracker();
 * obj->add(name,score);
 * string param_2 = obj->get();
 */