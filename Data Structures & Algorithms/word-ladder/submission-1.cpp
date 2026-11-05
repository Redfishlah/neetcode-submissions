class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dic(wordList.begin(), wordList.end());
        if(dic.find(endWord) == dic.end()) return 0; //no way to finish
        queue<string> q;
        q.push(beginWord);
        int level = 1;
        while(!q.empty()){
            int levelSize = q.size(); // if more than one, there might be one better or at least equal
            for(int i = 0; i < levelSize; i++){
                string cur = q.front();
                q.pop();
                if(cur == endWord) return level;
                for(int j = 0; j < cur.length(); j++){
                    char original = cur[j];
                    for(char c = 'a'; c <= 'z'; c++){
                        if(c == original) continue;
                        cur[j] = c; //change with this character
                        if(dic.find(cur) != dic.end()){ //if the generated is found
                            q.push(cur);
                            dic.erase(cur);
                        }
                    }
                    cur[j] = original;// back to original
                }
            }
            level++; // level increase if the round is over
        }
        return 0; // if never matched the target word
    }
};