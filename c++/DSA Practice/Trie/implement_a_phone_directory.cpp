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

    void printSuggestion(trieNode* curr, vector<string> &temp, string prefix){
        if(curr->isTerminal){
            temp.push_back(prefix);
        }
        for(char ch = 'a'; ch<='z'; ch++){
            trieNode* next = curr->children[ch -'a'];

            if(next != NULL){
                prefix.push_back(ch);
                printSuggestion(next, temp, prefix);
                prefix.pop_back();
            }

        }
    }

    vector<vector<string>>suggestions(string str){
        trieNode* prev = root;
        vector<vector<string>>output;
        string prefix = "";

        for(int i=0; i<str.length(); i++){
            char chlast = str[i];
            prefix.push_back(chlast);

            //check for last char

            trieNode* curr = prev->children[chlast - 'a'];

            if(curr == NULL){
                break;
            }
            vector<string> temp;
            printSuggestion(curr, temp, prefix);

            output.push_back(temp);
            temp.clear();
            prev = curr;
        }
        return output;
    }
};

vector<vector<string>> phoneDirectory(vector<string>&contactList, string &queryStr)
{
    //    creation of trie.
    trie *t = new trie();

    for(int i=0; i<contactList.size(); i++){
        string str = contactList[i];
        t->insertWord(str);
    }

    return t->suggestions(queryStr);
}