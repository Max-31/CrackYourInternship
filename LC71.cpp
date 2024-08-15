class Solution {
    // void print(stack<char> st){
    //     while(!st.empty()){
    //         cout<<st.top()<<" ";
    //         st.pop();
    //     }
    // }
public:
    string simplifyPath(string s) {
        stack<char> st, dot;
        st.push(s[0]);
        int n=s.size();

        for(int i=1; i<n; i++){
            if(s[i]=='.'){
                dot.push('.');
            }
            else if(s[i]=='/'){
                if(!dot.empty()){
                    if(dot.size()==1 && !st.empty() && st.top()=='/'){
                        if(!st.empty() && st.top()!=s[i])st.push(s[i]);
                        dot.pop();
                    }
                    else if(dot.size()==2 && !st.empty() && st.top()=='/'){
                        if(!st.empty()){
                            if(st.top()=='/' && st.size()>1)st.pop();

                            while(!st.empty() && st.top()!='/'){
                                st.pop();
                            }
                        }
                        if(!st.empty() && st.top()!=s[i])st.push(s[i]);
                        dot.pop(); dot.pop();
                    }
                    else{
                        while(!dot.empty()){
                            st.push(dot.top());
                            dot.pop();
                        }
                        st.push(s[i]);
                    }
                }
                else{
                    if(!st.empty() && st.top()!=s[i])st.push(s[i]);
                }
            }
            else{
                if(!dot.empty()){
                    while(!dot.empty()){
                        st.push(dot.top());
                        dot.pop();
                    }
                }
                st.push(s[i]);
            }
        }
        // while(!st.empty()){
        //     cout<<st.top()<<" ";
        //     st.pop();
        // }
        if(!dot.empty()){
            if(dot.size()==1 && !st.empty() && st.top()=='/'){
                
            }
            else if(dot.size()==2 && !st.empty() && st.top()=='/'){
                if(!st.empty()){
                    if(st.top()=='/')st.pop();

                    while(!st.empty() && st.top()!='/'){
                        st.pop();
                    }
                }
                // if(!st.empty() && st.top()!=s[i])st.push(s[i]);
                dot.pop(); dot.pop();
            }
            else{
                while(!dot.empty()){
                    st.push(dot.top());
                    dot.pop();
                }
                // st.push(s[i]);
            }
        }
        if(st.size()>1 && st.top()=='/') st.pop();

        if(st.empty()) st.push('/');

        string ans="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};