#include<iostream>
using namespace std;

class stack{
    // properties
    public:
    int top;
    int *arr;
    int size;
    // Behaviour
    stack(int size){
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    void push(int val){
        if((size-top)>1){
            top++;
            arr[top] = val;

        }
        else{
            cout<<"Stack overflow"<<endl;
        }
    }
    void pop(){
        if(top>=0){
            top--;
        }
        else{
            cout<<"Stack underFlow";
        }

    }
    int peek(){
        if(top>=0){
            return arr[top];
        }
    }
    bool isEmpty(){
        if(top==-1)
            return true;
        else
            return false;
    }
};
int main(){
    stack st(5);
    st.push(22);
    st.push(12);
    st.push(19);
    cout<<st.peek()<<endl;
    st.pop();
    cout<<st.peek()<<endl;  
}