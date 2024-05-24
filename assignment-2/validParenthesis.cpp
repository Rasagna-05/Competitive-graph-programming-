class Solution {
public:
    bool isValid(string s) {
    unordered_map<char,int> m={{'(',1},{'{',2},{'[',3},{')',-1},{'}',-2},{']',-3}};
        stack<char> st;
        int n=s.size();
        for(int i=0;i<n;i++){
           if(m[s[i]]>0){
            st.push(s[i]);
           }else{
            if(st.empty()){
                return false;
            }
            if(m[s[i]]+m[st.top()]==0){
                st.pop();
                continue;
            }else{
                return false;
            }
           }
        }
        if(st.empty()){
            return true;
        }else{
            return false;
        }
    }
};
