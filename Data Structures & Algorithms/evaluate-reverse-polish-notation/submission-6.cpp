class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        
        stack<string> stc;
        if(tokens.empty())return 0;
        if(tokens.size() == 1)return stoi(tokens[0]);
        int res;
        
        for(string token:tokens){
            if(token == "+" || token == "-" || token == "*" || token == "/"){
                int op2 = stoi(stc.top());
                stc.pop();
                int op1 = stoi(stc.top());
                stc.pop();
                res = evalOp(op1,op2,token[0]);
                stc.push(to_string(res));
            }else{
                stc.push(token);
            }
           
        }
        return stoi(stc.top());
    }
    int evalOp(int op1,int op2,char op){
        switch(op){
            case '+':
                return op1+op2;
            case '-':
                return op1-op2;
            case '*':
                return op1*op2;
            case '/':
                return op1/op2;
        }
        return -1;
    }
};
