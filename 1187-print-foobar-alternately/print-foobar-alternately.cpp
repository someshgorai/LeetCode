class FooBar {
private:
    int n;
    mutex mtx;
    condition_variable cv;
    int turn = 0;

public:
    FooBar(int n) {
        this->n = n;
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            unique_lock<mutex> lock(mtx);
            while (turn == 1) {
                cv.wait(lock);
            }
        	// printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();
            turn = 1;
            cv.notify_one();
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            unique_lock<mutex> lock(mtx);
            while (turn == 0) {
                cv.wait(lock);
            }
        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();
            turn = 0;
            cv.notify_one();
        }
    }
};