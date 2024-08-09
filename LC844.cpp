class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string finals="", finalt="";

        stack<char> st;

        for(int i=0; i<s.size(); i++){
            if(s[i]=='#'){
                if(!st.empty()){
                    st.pop();
                }
            }
            else st.push(s[i]);
        }

        while(!st.empty()){
            finals+=st.top();
            st.pop();
        }
        

        for(int i=0; i<t.size(); i++){
            if(t[i]=='#'){
                if(!st.empty()){
                    st.pop();
                }
            }
            else st.push(t[i]);
        }

        while(!st.empty()){
            finalt+=st.top();
            st.pop();
        }

        return finals==finalt;
    }
};