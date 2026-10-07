class Solution {
private:
    struct TrieNode{
        TrieNode* children[26] = {nullptr};
        string word = ""; // Store the full word directly at the end node
    };
    TrieNode* root; // starts of null
    void insert(string word){
        TrieNode* cur = root;
        for(auto c: word){
            int n = c - 'a';
            if(cur -> children[n] == nullptr) cur -> children[n] = new TrieNode();
            cur = cur -> children[n]; 
        }
        cur -> word = word;
    }
    void dfs(vector<vector<char>>& board, int r, int c, TrieNode* cur, vector<string>& res){
        char letter = board[r][c];
        if(letter == '#') return;
        int n = letter - 'a';
        if(cur -> children[n] == nullptr) return;
        cur = cur -> children[n];
        if(cur -> word != ""){
            res.push_back(cur -> word);
            cur -> word = "";
        }
        board[r][c] = '#';
        int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        for(int i = 0; i < 4; i++){
            int rr = r + dir[i][0], cc = c + dir[i][1];
            if(rr >= 0 && rr < board.size() && cc >= 0 && cc < board[0].size() && board[rr][cc] != '#') dfs(board, rr, cc, cur, res);
        }
        board[r][c] = letter;
    }

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        root = new TrieNode();
        for(string w: words){
            insert(w);
        }
        vector<string> res;
        for(int r = 0; r < board.size(); r++){
            for(int c = 0; c < board[0].size(); c++){
                dfs(board, r, c, root, res);
            } 
        }
        return res;
    }
};
