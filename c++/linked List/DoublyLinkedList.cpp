#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;

    Node(int data){
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }

    ~Node(){
        this->data = data;
        if(next != NULL){
            delete next;
            next=NULL;
        }
    }
};

void getLength(Node* &head){
    Node* temp = head;
    int len = 0;

    while(temp != NULL){
        len++;
        temp = temp->next;
    }
    cout<<len<<endl;
}

void insertAtHead(Node* &head, int data){
    Node* temp = new Node(data);
    temp ->next = head;
    head->prev = temp;
    head = temp;
}

void insertAtTail(Node* tail, int data){
    Node* temp = new Node(data);
    tail->next = temp;
    temp->prev = tail;
    tail = temp; 
}

void insertAtPosition(Node* &head,  Node* &tail,int position, int data){
    if(position==1){
        insertAtHead(head,data);
        return;
    }

    Node* temp = head;
    int cnt = 1;
    while(cnt<position-1){
        temp = temp->next;
        cnt++;
    }
    if(temp->next==NULL){
        insertAtTail(tail,data);
        return;
    }
    Node* newNode = new Node(data);
    newNode->next=temp->next;
    temp->next->prev = newNode;
    temp->next = newNode;
    newNode->prev = temp;
}

void deleteNode(Node* &head, int pos){
    if(pos==1){
        Node* temp = head;
        temp->next->prev = NULL;
        head = temp->next;
        temp->next = NULL;
        delete temp;
        return;
    }
    Node* temp = head;
    Node* curr = NULL;
    int cnt = 1;

    while(cnt<pos){
        curr = temp;
        temp = temp->next;
        cnt++;
    }
    temp->prev = NULL;
    curr->next=temp->next;
    temp->next = NULL;
    delete temp;
}

void print(Node* &head){
    Node* temp = head;
    while(temp !=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }cout<<endl;
} 

int main(){
    Node* newNode = new Node(10);
    Node* head = newNode;
    Node*tail = newNode;
    print(head);
    // getLength(head);
    insertAtHead(head,12);
    print(head);
    insertAtHead(head,14);
    print(head);
    insertAtHead(head,11);
    print(head);
    insertAtHead(head,19);
    print(head);
    insertAtTail(tail, 22);
    print(head);
    insertAtPosition(head,tail,4,20);
    print(head);
    deleteNode(head,5);
    print(head);
}