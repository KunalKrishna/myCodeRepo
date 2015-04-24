#include <iostream>
#include <vector>
#include <climits>
using namespace std;

    vector<int> myStack;
    int i = -1;
    int min=0;

    void push(int x) {
        min = x;
        if(x<getMin()){
            min =x;
        }

        myStack.push_back(x);
        i++;
    }

    void pop() {
        if(i==0) return;
        myStack.pop_back();
        i--;
    }

    int top() {
        if(i<0) return -1;
        return myStack[i];
    }

    int getMin() {
        if(i<0) return INT_MIN;
        return min;
    }

int main() {

    cout<<getMin()<<endl;
    return 0;

}
