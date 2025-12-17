class CustomStack {
public:
    stack<int> s;
    int maxsize;
    int dummy;  
    CustomStack(int maxSize) {
        maxsize = maxSize;
        dummy = maxSize;
    }
    void push(int x) {
        if (dummy > 0) {
            s.push(x);
            dummy--;   
        }
    }
    int pop() {
        if (!s.empty()) {
            int val = s.top();
            s.pop();
            dummy++;  
            return val;
        }
        return -1;
    }

    void increment(int k, int val) {
        stack<int> temp;
        while (!s.empty()) {
            temp.push(s.top());
            s.pop();
        }
        while (!temp.empty() && k > 0) {
            s.push(temp.top() + val);
            temp.pop();
            k--;
        }
        while (!temp.empty()) {
            s.push(temp.top());
            temp.pop();
        }
    }
};
