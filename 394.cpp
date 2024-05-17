class Solution {
public:
    string decodeString(string s) {
        
        stack<char>st;
        for(auto x:s){
            if(x!=']'){
                st.push(x);
            }
            else{
                string s1="";
                while(st.top()!='['){
                    s1.push_back(st.top());
                    st.pop();
                }
                reverse(s1.begin(),s1.end());
                st.pop();
                int c=0;
                int m=1;
                while(st.size()>0 && ( int(st.top())>=48 && int(st.top())<=57 ))
                {
                    auto node=st.top();
                    st.pop();
                    
                    int num=(node-'0')*m;
                    c+=num;
                    m=m*10;
                }
                while(c--){
                    for(auto x:s1){
                        st.push(x);
                    }
                }
            }
        }
        string ans="";
        while(st.size()>0){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
