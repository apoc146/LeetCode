class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;

        for(int i=0;i<tokens.size();i++){
            int isNum=0;
            string tok=tokens[i];
            int ele;
            string eleStr="";

            if(tok=="+"|| tok=="-"|| tok=="*" || tok=="/"){
                ele=tok[0];
            }else{
                isNum=1;
                ele=stoi(tok);
            }

            if(isNum){
                stk.push(ele);
            }else{
                //operand
                int op2=stk.top();
                stk.pop();
                int op1=stk.top();
                stk.pop();
                char test=char(ele);
                switch(char(ele)){
                    case('/'):
                        stk.push(op1/op2);
                        break;
                    case('*'):
                        stk.push(op1*op2);
                        break;
                    case('+'):
                        stk.push(op1+op2);
                        break;
                    case('-'):
                        stk.push(op1-op2);
                        break;
                    default:
                        throw "default error\n";
                }
            }

        }
        return stk.top();
    }
};