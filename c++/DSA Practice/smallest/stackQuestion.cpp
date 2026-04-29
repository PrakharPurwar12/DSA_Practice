#include <bits/stdc++.h>
using namespace std;

class TwoStack {
public:
    int *arr;
    int s;
    int top1;
    int top2;

    // Constructor
    TwoStack(int s) {
        this->s = s;
        arr = new int[s];
        top1 = -1;
        top2 = s;
    }
    
    // Push in stack 1
    void push1(int num) {
        if (top2 - top1 > 1) {
            top1++;
            arr[top1] = num;
        }
    }

    // Push in stack 2
    void push2(int num) {
        if (top2 - top1 > 1) {
            top2--;
            arr[top2] = num;
        } 
    }

    // Pop from stack 1
    int pop1() {
        if (top1 >= 0) {
            int ans = arr[top1];
            top1--;
            return ans;
        } else {
            cout << "Stack Underflow in Stack1" << endl;
            return -1;
        }
    }

    // Pop from stack 2
    int pop2() {
        if (top2 < s) {
            int ans = arr[top2];
            top2++;
            return ans;
        } else {
            cout << "Stack Underflow in Stack2" << endl;
            return -1;
        }
    }
};

// Driver function
int main() {
    TwoStack twoStack(3);
    
    twoStack.push1(2);  // pushing 2 in stack1
    twoStack.push1(4);  // pushing 4 in stack1
    twoStack.push1(3);  // pushing 3 in stack1
    twoStack.push2(5);  // pushing 5 in stack2 (overflow)
    cout << twoStack.pop2() << endl; // stack2 empty => -1
    cout << twoStack.pop1() << endl; // stack1 => 3
    twoStack.push2(6);  // pushing 6 in stack2
    cout << twoStack.pop2() << endl; // stack2 => 6
    cout << twoStack.pop1() << endl; // stack1 => 4
    twoStack.push2(7);  // pushing 7 in stack2
}
