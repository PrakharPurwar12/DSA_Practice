#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data=data;
        this->next = NULL;
    }


};

void insertAtHead(Node* &head,int data){
    Node* temp = new Node(data);
    temp->next = head;
    head=temp;
}

void insertAtTail(Node* &tail,int data){
    Node* temp = new Node(data);

    tail->next = temp;
    tail = temp;

}   

void insertAtPosition(Node* &head, Node* &tail, int data, int position){
    
    if(position == 1){
        insertAtHead(head,data);
        return;
    }
    Node* temp = head;
    int  cnt = 1;
    while(cnt < position-1){
        temp = temp->next;
        cnt++;
    }
    
    if(temp->next==NULL){
        insertAtTail(tail,data);
        return;
    }
    Node* newNode = new Node(data);
    newNode->next=temp->next;
    temp->next = newNode;


}
void print(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main(){
    Node* newNode = new Node(10);
    
    Node* head = newNode;
    Node* tail = head;
    print(head);
    insertAtHead(head,12);
    print(head);
    insertAtTail(tail,15);
    print(head);
    insertAtPosition(head,tail,20,4);
    print(head);
    cout<< tail->data<<" ";
}