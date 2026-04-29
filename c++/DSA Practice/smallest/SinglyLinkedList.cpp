#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

void insertAtHead(Node* &head, int d){
    Node* temp = new Node(d);
    temp->next = head;
    head = temp;
}

void insertAtEnd(Node* &head, int d){
    Node* newNode = new Node(d);
    if(head == NULL){
        head = newNode;
        return;
    }
    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
}

void insertAtpos(Node* &head, int pos, int d){
    Node* newNode = new Node(d);
    if(pos == 1){
        newNode->next = head;
        head = newNode;
        return;
    }
    Node* temp = head;
    for(int i=1; i<pos-1 && temp!=NULL; i++){
        temp = temp->next;
    }

    if(temp == NULL) return;
    newNode->next = temp->next;
    temp->next = newNode;
}

void removeFirstNode(Node* &head){
    if(head == NULL) return;
    Node* temp = head;
    head = head->next;
    delete temp;
}
void removeLastNode(Node* &head){
    if(head==NULL) return;
    if(head->next == NULL) delete head;

    Node* secondLast = head;
    while(secondLast->next->next != NULL){
        secondLast = secondLast->next;
    }
    delete(secondLast->next);
    secondLast->next = NULL;
}
void removeAtPos(Node* &head, int pos){
    if(head==NULL || pos<1){
        return;
    }
    if(pos==1){
        Node*temp=head;
        head=head->next;
        delete temp;
    }

    Node* current = head;

    for(int i=1; i<pos-1 && current != NULL; i++){
        current = current->next;

    }

    Node* temp = current->next;
    current->next = current->next->next;
    delete temp;

}
void print(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data <<" ";
        temp = temp->next;
    }
    cout<<endl;
}
int main(){
    Node* node1 = new Node(10);
    // cout<< node1->data<<endl;
    // cout<<node1->next<<endl;

    Node* head = node1;
    print(head);
    insertAtHead(head, 12);
    print(head);
    insertAtHead(head,15);
    print(head);
    insertAtEnd(head, 22);
    print(head);
    insertAtpos(head,5,11);
    print(head);
    removeFirstNode(head);
    print(head);
    removeLastNode(head);
    print(head);
    removeAtPos(head, 2);
    print(head);
    

}