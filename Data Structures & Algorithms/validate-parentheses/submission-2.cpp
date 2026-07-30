class Solution {
public:
    bool isValid(string s) {
        vector<char> tmp;
        for(char ss:s){
            if(ss == '(' || ss == '{' || ss == '[') tmp.push_back(ss);
            else if(tmp.empty()) return false;
            else if(exam(tmp.back(), ss)) tmp.pop_back();
            else return false;
        }
        return tmp.empty();
    }
    bool exam(char c, char rc){
        if(c == '(' && rc == ')') return true;
        if(c == '{' && rc == '}') return true;
        if(c == '[' && rc == ']') return true;
        return false;
    }
};
// '(', ')', '{', '}', '[' and ']'