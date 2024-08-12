class Solution
{
    int operate(int a, int b, char c){
        if(c=='+') return a+b;
        if(c=='-') return a-b;
        if(c=='*') return a*b;
        if(c=='/') return a/b;
        return 0;
    }
    public:
    //Function to evaluate a postfix expression.
    int evaluatePostfix(string str){
        stack<int>s;
        
        for(int i=0; i<str.size(); i++){
            if('0'<=str[i] && str[i]<='9'){
                s.push(str[i]-'0');
            }
            else{
                int b= s.top(); s.pop();
                int a= s.top(); s.pop();
                
                s.push(operate(a,b,str[i]));
            }
        }
        return s.top();
    }
};