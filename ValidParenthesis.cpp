class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int n=s.size();
        if(s[0]==')' or s[0]=='}' or s[0]==']') return false;
        for(int i=0;i<n;i++){
            if(st.empty()) st.push(s[i]);
            else if(s[i]==']' and st.top()=='[') st.pop();
            else if(s[i]==')' and st.top()=='(') st.pop();
            else if(s[i]=='}' and st.top()=='{') st.pop();
            else st.push(s[i]);
        }
        if(st.empty()) return true;
        else return false;
    }
};
