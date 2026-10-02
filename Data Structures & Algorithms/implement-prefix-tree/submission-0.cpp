class PrefixTree {
private:
    struct TrieNode {
        TrieNode* children[26];
        bool isEndOfWord;
        TrieNode() {
            isEndOfWord = false;
            for (int i = 0; i < 26; i++) {
                children[i] = nullptr;
            }
        }
    };
    TrieNode* root; // the empty root that starts of null

public:
    PrefixTree() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* cur = root;
        for(auto w: word){
            int n = w - 'a';
            if(cur -> children[n] == nullptr){
                cur -> children[n] = new TrieNode();
            }
            cur = cur -> children[n];
        }
        cur -> isEndOfWord = true;
    }
    
    bool search(string word) {
        TrieNode* cur = root;
        for(auto w: word){
            int n = w - 'a';
            if(cur -> children[n] == nullptr) return false;
            cur = cur -> children[n];
        }
        return cur -> isEndOfWord;
    }
    
    bool startsWith(string prefix) {
        TrieNode* cur = root;
        for(auto c: prefix){
            int n = c - 'a';
            if(cur -> children[n] == nullptr) return false;
            cur = cur -> children[n];
        }
        return true;
    }
};
