class ZeroEvenOdd {
private:
    int n;
    int turn = 0;
    int i = 1;
    mutex mtx;
    condition_variable cv;

public:
    ZeroEvenOdd(int n) {
        this->n = n;
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        unique_lock<mutex> lock(mtx);
        while (i <= n) {
            while (turn != 0 && i <= n) {
                cv.wait(lock);
            }
            if (i > n) break;

            printNumber(0);

            if (i & 1) turn = 1;
            else turn = 2;

            cv.notify_all();
        }
    }

    void even(function<void(int)> printNumber) {
        unique_lock<mutex> lock(mtx);
        while (i <= n) {
            while (turn != 2 && i <= n) {
                cv.wait(lock);
            }
            if (i > n) break;

            printNumber(i++);

            turn = 0;
            cv.notify_all();
        }
    }

    void odd(function<void(int)> printNumber) {
        unique_lock<mutex> lock(mtx);
        while (i <= n) {
            while (turn != 1 && i <= n) {
                cv.wait(lock);
            }
            if (i > n) break;

            printNumber(i++);

            turn = 0;
            cv.notify_all();
        }
    }
};