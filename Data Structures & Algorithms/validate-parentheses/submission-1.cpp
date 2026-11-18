class Solution {
public:
    bool isValid(string s) {
        stack<char>stack;
        for(char c: s){
            if (c == '(' || c=='{' || c=='['){stack.push(c);continue;}

            if(stack.empty())return false;
            if ((c == ')' && stack.top() !='(') || (c=='}' && stack.top() !='{') || (c==']' && stack.top() !='['))return false;
            stack.pop();
        }
       
        return stack.empty();
    }
};
