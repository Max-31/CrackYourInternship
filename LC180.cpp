class Solution {
    int oper(int a, int b, string c){
        if(c=="+") return a+b;
        if(c=="-") return a-b;
        if(c=="*") return a*b;
        if(c=="/") return a/b;
        return -1;
    }
public:
    int evalRPN(vector<string>& str) {
        stack<int>s;
        for(int i=0; i<str.size(); i++){
            if(str[i]=="+"||str[i]=="-"||str[i]=="*"||str[i]=="/"){
                int b= s.top(); s.pop();
                int a= s.top(); s.pop();

                int ans= oper(a, b, str[i]);

                s.push(ans);
            }
            else{
                string st= str[i];
                int a=0;

                if('0'<=st[0] && st[0]<='9'){
                    for(int i=0; i<st.size(); i++){
                        a*=10;
                        a+= st[i]-'0';
                    }
                }
                else{
                    int f=1;
                    if(st[0]=='-') f=-1;

                    for(int i=1; i<st.size(); i++){
                        a*=10;
                        a+= st[i]-'0';
                    }

                    a*=f;
                }
                s.push(a);
            }
        }

        return s.top();
    }
};