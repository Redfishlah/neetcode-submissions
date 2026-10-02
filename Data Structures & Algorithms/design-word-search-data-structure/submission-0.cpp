class WordDictionary {
private:
    struct TrieNode{
        TrieNode* children[26] = {nullptr};
        bool isEnd = false;
    };
    TrieNode* root; // starts of null
    bool dfs(const string& word, int n, TrieNode* cur){
        if(n == word.length()) return cur -> isEnd;
        char c = word[n];
        // case with .
        if(c == '.'){
            for(int i = 0; i < 26; i++){
                if(cur -> children[i] != nullptr){ // see if any connection is valid
                    if(dfs(word, n + 1, cur -> children[i])) return true;
                }
            }
            return false;
        }
        // normal case
        else{
            int index = c - 'a';
            if(cur -> children[index] == nullptr) return false;
            return dfs(word, n + 1, cur -> children[index]);
        }
    }


public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* cur = root;
        for(auto w: word){
            int n = w - 'a';
            if(cur -> children[n] == nullptr) cur -> children[n] = new TrieNode();
            cur = cur -> children[n];
        }
        cur -> isEnd = true;
    }
    
    bool search(string word) {
        return dfs(word, 0, root);
    }
};
