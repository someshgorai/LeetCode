class MedianFinder {
public:
    int lsize = 0, rsize = 0;
    priority_queue<double, vector<double>, greater<>> minpq;
    priority_queue<double> maxpq;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        maxpq.push(num);
        minpq.push(maxpq.top());
        maxpq.pop();
        lsize++;

        if (lsize > rsize) {
            int temp = minpq.top();
            minpq.pop();

            maxpq.push(temp);
            lsize--;
            rsize++;
        }
    }
    
    double findMedian() {
        if (lsize == rsize) return (minpq.top() + maxpq.top()) / 2;
        return maxpq.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */