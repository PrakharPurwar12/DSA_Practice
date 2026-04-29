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

    void insertUtil(trieNode* root, string word){
        //base case
        if(word.length()==0){
            root->isTerminal = true;
            return;
        }
        int index = word[0] - 'a';
        
    }

    void insertWord(string word){
        insertUtil(root, word);
    }
}

int main(){


    return 0;
}