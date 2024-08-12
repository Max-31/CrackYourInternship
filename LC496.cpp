class Solution {
public:
    vector<int> bruteforce(vector<int>&v1, vector<int>&v2){
        int n1= v1.size(); 
        int n2= v2.size();
        unordered_map<int, int> m;
        
        for(int i=0; i<n1; i++){
            for(int j=0; j<n2; j++){
                if(v1[i]==v2[j]){
                    m[v1[i]]= j;
                    break;
                }
            }
        }

        int flag;
        vector<int> ans;
        for(int i=0; i<n1; i++){
            flag=0;
            for(int j=m[v1[i]]; j<n2; j++){
                if(v1[i]<v2[j]){
                    ans.push_back(v2[j]);
                    flag=1;
                    break;
                }
            }
            if(flag==0) ans.push_back(-1);
        }

        return ans;
    }

    vector<int> optimized(vector<int>&v1, vector<int>&v2){
        int n1= v1.size();
        int n2= v2.size();
        stack<int> st;
        unordered_map<int, int> m;
        vector<int> ans;

        for(int i= n2-1; i>=0; i--){
            if(st.empty()){
                m[v2[i]]= -1;
                st.push(v2[i]);
            }
            else{
                while(!st.empty()){
                    if(st.top()>v2[i]){
                        m[v2[i]]= st.top();
                        st.push(v2[i]);
                        break;
                    }
                    else{
                        st.pop();
                    }
                }
                if(st.empty()){
                    m[v2[i]]= -1;
                    st.push(v2[i]);
                }

            }
        }

        for(int i=0; i<n1; i++){
            ans.push_back(m[v1[i]]);
        }

        return ans;
    }

    vector<int> nextGreaterElement(vector<int>& v1, vector<int>& v2) {
        // return bruteforce(v1, v2);
        return optimized(v1, v2);
    }
};