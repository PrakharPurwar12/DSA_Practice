#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;

    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* buildTree(Node* root){
    cout<<"Enter Data: "<<endl;
    int data;
    cin>>data;
    root = new Node(data);
    if(data == -1){
        return NULL;
    }
    cout<<"Enter the data for insert in left of "<<data<<endl;
    root->left = buildTree(root->left);
    cout<<"Enter the data for insert in right of "<<data<<endl;
    root->right = buildTree(root->right);
    return root;
}

void inOrder(Node* root){
    if(root==NULL){
        return;
    }

    inOrder(root->left); //L
    cout<<root->data<<" "; //N
    inOrder(root->right); // R
    
}

void preOrder(Node* root){
    if(root==NULL){
        return;
    }
    
    cout<< root->data<<" "; //N
    preOrder(root->left); //L
    preOrder(root->right); //R
}

void postOrder(Node* root){
    if(root==NULL){
        return;
    }
    postOrder(root->left); //L
    postOrder(root->right); //R
    cout<<root->data<<" "; //N
}
int main(){
    // 1 2 3 -1 -1 4 -1 -1 5 6 -1 -1 -1
    Node* root = NULL;
    root = buildTree(root);
    cout<<"In Order Traversal"<<endl;
    inOrder(root);
    cout<<"\nPre Order Traversal"<<endl;
    preOrder(root);
    cout<<"\nPost Order Traversal"<<endl;
    postOrder(root);
    cout<<endl;
    return 0;
}