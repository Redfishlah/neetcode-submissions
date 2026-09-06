class Solution {
public:
    bool checkValidString(string s) {
        stack<int> l, ss;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '(') l.push(i);
            else if(s[i] == '*') ss.push(i);
            else{
                if(l.empty() && ss.empty()) return false;
                if(!l.empty()) l.pop();
                else ss.pop();
            }
        }
        if(l.size() > ss.size()) return false;
        else{
            while(!l.empty() && !ss.empty()){
                if(l.top() > ss.top()) return false;
                l.pop();
                ss.pop();
            }
        }
        return l.empty();
    }
};
