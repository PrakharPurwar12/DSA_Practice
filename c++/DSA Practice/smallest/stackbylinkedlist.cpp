#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int x){
        this->data = x;
        this->next = NULL;
    }
};
class myStack{
    public:
    Node* top;
    int count;
    myStack(){
        top = NULL;
        count =0;
    }

    void push(int x){
        Node* temp = new Node(x);
        temp->next = top;
        top = temp;
        count++;
    }

    int pop(){
        if(top==NULL){
            cout <<"stack is underflow "<<endl;
            return -1;
        }
        Node* temp = top;
        top=top->next;
        int val = temp->data;

        delete temp;
        count--;
        return val;
    }
    int peek(){
        if(top==NULL){
            cout<<"stack is empty"<<endl;
            return -1;
        }
        return top->data;
    }

    bool isEmpty(){
        return top==NULL;
    }
    int size(){
        return count;

    }

};


int main(){
    myStack st;
    st.push(3);
    st.push(4);
    st.push(5);

    cout<<"popped: "<< st.pop()<<endl;
    cout<<"peek element: "<<st.peek()<<endl;
    cout<<"size: "<<st.size()<<endl;

    if(st.isEmpty()){
        cout<<"stack is empty"<<endl;
    }
    else{
        cout<<"stack is not empty"<<endl;
    }
}
