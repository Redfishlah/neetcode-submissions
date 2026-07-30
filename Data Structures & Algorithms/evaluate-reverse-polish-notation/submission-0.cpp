class Solution {
public:
    stack<string> tmp;
    int evalRPN(vector<string>& tokens) {
        int res = 0;
        for(int i = 0; i < tokens.size(); i++){
            if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") count(tokens[i]);
            else tmp.push(tokens[i]);
        }
        return stoi(tmp.top());
    }
    void count(string op){
        int x = stoi(tmp.top());
        tmp.pop();
        int y = stoi(tmp.top());
        tmp.pop();
        if(op == "+") tmp.push(to_string(y + x));
        if(op == "-") tmp.push(to_string(y - x));
        if(op == "*") tmp.push(to_string(y * x));
        if(op == "/") tmp.push(to_string(y / x));
    }
};