#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;

        Node(int d){
            this->data = d;
            this->left = NULL;
            this->right = NULL;
        }
};

Node* insert(Node* root, int val){
    if(root==NULL){
        return new Node(val);
    }

    if(val<root->data){
        root->left = insert(root->left, val);
    }
    else if(val > root->data){
        root->right = insert(root->right, val);
    }
    return root;
}
void inorder(Node* root){
    if(root==NULL) return;

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void preorder(Node* root){
    if(root==NULL) return;

    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(Node* root){
    if(root==NULL) return;
    preorder(root->left);
    preorder(root->right);
    cout<< root->data<<" ";

}
Node* findMin(Node* root){
    while(root->left != NULL){
        root = root->left;
    }
    return root;
}

Node* deleteNode(Node* root, int val){
    if(root==NULL) return root;

    if(val < root->data){
        root->left = deleteNode(root->left,val);
    }
    else if(val > root->data){
        root->right = deleteNode(root->right, val);
    }
    else{
        if(root->left == NULL){
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if(root->right == NULL){
            Node* temp = root->left;
            delete root;
            return temp;
        }
        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;

}

bool search(Node* root, int val){
    if(root==NULL) return false;
    if(root->data == val)
        return true;
    else if(val<root->data){
        return search(root->left, val);
    }
    else{
        return search(root->right, val);
    }
}
int main(){
    
     Node* root = NULL;

    // Insert nodes
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    cout << "Inorder (sorted): ";
    inorder(root);
    cout << endl;

    cout << "Preorder: ";
    preorder(root);
    cout << endl;

    cout << "Postorder: ";
    postorder(root);
    cout << endl;

    // Delete operations
    cout << "\nDeleting 20...\n";
    root = deleteNode(root, 20);
    cout << "Inorder after deleting 20: ";
    inorder(root);
    cout << endl;

    cout << "\nDeleting 30...\n";
    root = deleteNode(root, 30);
    cout << "Inorder after deleting 30: ";
    inorder(root);
    cout << endl;

    cout << "\nDeleting 50...\n";
    root = deleteNode(root, 50);
    cout << "Inorder after deleting 50: ";
    inorder(root);
    cout << endl;

    int key1 = 70, key2 = 25;
    cout << "\nSearching for " << key1 << ": ";
    cout << (search(root, key1) ? "Found " : "Not Found ") << endl;

    cout << "Searching for " << key2 << ": ";
    cout << (search(root, key2) ? "Found " : "Not Found ") << endl;


    return 0;
}