// http://www.geeksforgeeks.org/reverse-a-stack-using-recursion/

#include<iostream>
#include<stack>
using namespace std;

void printStack(stack<int> st)
{
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;
}

void insertAtBottom(stack<int> &st, int data)
{
    if( (st.empty()) ){
        st.push(data);
    }
    else {
        int temp = st.top();
        st.pop();
        insertAtBottom(st, data);
        st.push(temp);
    }
}

void reverseStack(stack<int> &st)
{
    if( !(st.empty()) )
    {
        int temp = st.top();
        st.pop();
        reverseStack(st);
        insertAtBottom(st, temp);
    }
}

int main()
{
    stack<int> st ;
    st.push(4);
    st.push(3);
    st.push(2);
    st.push(1);
    printStack(st);

    reverseStack(st);

    printStack(st);
    return 0;
}
