class Node {
public:
    string url;
    Node* next;
    Node* back;
    Node() : url(""), next(nullptr), back(nullptr) {};
    Node(string page) : url(page), next(nullptr), back(nullptr) {};
    Node(string page, Node* nextPage, Node* backPage) :
        url(page), next(nextPage), back(backPage) {};
};
class BrowserHistory {
public:
    Node* tab;
    BrowserHistory(string homepage) {
        tab = new Node(homepage);
    }
    
    void visit(string url) {
        Node* newPage = new Node(url);
        tab->next = newPage;
        newPage->back = tab;
        tab = newPage;
    }
    
    string back(int steps) {
        while (steps && tab->back) {
            tab = tab->back;
            steps--;
        }
        return tab->url;
    }
    
    string forward(int steps) {
        while(steps && tab->next) {
            tab = tab->next;
            steps--;
        }
        return tab->url;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */