#include<iostream>
using namespace std;

class stack{
    public:
        int *arr;
        int size;
        int top;

    stack(int size){
        this->size = size;
        arr = new int[size];
        top = -1;
    }
    void push(int element){
        if(size-top>1){
            top++;
            arr[top] = element;
        }
        else{
            cout<< "Stack is overflow"<<endl;
            return;
        }

    }
    void pop(){
        if(top>=0){
            top--;
        }
        else{
            cout<<"Stack is underflow"<<endl;
        }
    }
    int peek(){
        if(top>=0){
            return arr[top];
        }
        else{
            cout<<"stack is empty"<<endl;
            return -1;
        }
    }
    bool isEmpty(){
        if(top<0){
            return true;
        }
        else{
            return false;
        }
    }
};


int main(){
    stack st(5);
    st.push(22);
    st.push(14);
    st.push(26);
    st.push(11);
    cout<<st.peek()<<endl;
    st.pop();
    cout<<st.peek()<<endl;
    st.pop();
    cout<<st.peek()<<endl;
    st.pop();
    cout<<st.peek()<<endl;
    st.pop();
    cout<<st.peek()<<endl;   

}