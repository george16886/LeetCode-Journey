#include <iostream>
#include <stack>
using namespace std;

class MinStack1 {
   private:
    stack<int> s;
    stack<int> sMin;

   public:
    /** initialize your data structure here. */
    MinStack1() {
    }

    void push(int x) {
        if (sMin.empty() || x <= sMin.top()) sMin.push(x);
        s.push(x);
    }

    void pop() {
        if (s.top() == sMin.top()) sMin.pop();
        s.pop();
    }

    int top() {
        return s.top();
    }

    int getMin() {
        return sMin.top();
    }
};

class MinStack {
   private:
    stack<int> s;
    int min;

   public:
    /** initialize your data structure here. */
    MinStack() {
        min = INT32_MAX;
    }

    void push(int x) {
        if (x <= min) {
            s.push(min);
            min = x;
        }
        s.push(x);
    }

    void pop() {
        int top = s.top();
        s.pop();
        if (top == min) {
            min = s.top();
            s.pop();
        }
    }

    int top() {
        return s.top();
    }

    int getMin() {
        return min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

int main(int argc, char** argv) {
    MinStack* obj = new MinStack();
    cout << "MinStack* obj = new MinStack();" << endl;
    obj->push(-2);
    obj->push(0);
    obj->push(-3);
    int param_4 = obj->getMin();
    cout << "MinStack->push(-2);" << endl;
    cout << "MinStack->push(0);" << endl;
    cout << "MinStack->push(-3);" << endl;
    cout << "MinStack->getMin();\t";
    cout << "--> Returns " << param_4 << "." << endl;
    obj->pop();
    cout << "MinStack->pop()" << endl;
    int param_3 = obj->top();
    cout << "MinStack->top();\t";
    cout << "--> Returns " << param_3 << "." << endl;
    param_4 = obj->getMin();
    cout << "MinStack->getMin();\t";
    cout << "--> Returns " << param_4 << "." << endl;

    MinStack* obj2 = new MinStack();
    cout << endl;
    obj2->push(0);
    obj2->push(1);
    obj2->push(0);
    cout << obj2->getMin() << endl;
    obj2->pop();
    cout << obj2->getMin() << endl;

    return 0;
}