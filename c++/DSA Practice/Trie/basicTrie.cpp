#include<iostream>
using namespace std;

class trieNode{
    public:
    char data;
    trieNode* children[26];
    bool isTerminal;

    trieNode(char ch){
        data = ch;
        for(int i=0; i<26; i++){
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class trie{
    trieNode* root;
    public:
    trie(){
        root = new trieNode('\0');
    }


    void insertUtil(trieNode* root, string word){
        //base case
        if(word.length()==0){
            root->isTerminal = true;
            return;
        }
        int index = word[0] - 'a';
        trieNode* child;

        if(root->children[index] != NULL){
            child = root->children[index];
        }
        else{
            child = new trieNode(word[0]);
            root -> children[index] = child;
        }
        insertUtil(child, word.substr(1));
        
    }

    void insertWord(string word){
        insertUtil(root, word);
    }

    bool searchutil(trieNode* root, string word){
        if(word.length()==0){
            return root->isTerminal;
        }
        int index = word[0]-'a';
        trieNode* child;
        if(root->children[index] != NULL){
            child = root->children[index];
        }
        else{
            return false;
        }
        return searchutil(child, word.substr(1));
    }

    bool searchWord(string word){
        return searchutil(root, word);
    }

    bool removeUtil(trieNode* root, string word){
        if(!searchutil(root, word)){
            return false;
        }

        if(word.length()==0){
            root->isTerminal = false;

            for(int i=0; i<26; i++){
                if(root->children[i] != NULL){
                    return false;
                }
            }
            return true;
        }

        int index = word[0]-'a';
        trieNode* child = root->children[index];

        bool shouldDeleteChild = removeUtil(child, word.substr(1));

        if(shouldDeleteChild){
            delete child;
            root->children[index] = NULL;
        }

        if(root->isTerminal){
            return false;
        }

        for(int i=0; i<26; i++){
            if(root->children[i] != NULL){
                return false;
            }
        }

        return true;
    }
    void removeWord(string word){
        removeUtil(root, word);
    }
};

int main(){
    trie t;
    t.insertWord("apple");
    t.insertWord("app");
    cout<<t.searchWord("app")<<endl;

    t.removeWord("app");
    cout<<t.searchWord("app")<<endl;
    return 0;
}
