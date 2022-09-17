#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
    string s;
    cin >> s;

    stack<int> st;
    for(int i = 0; i < s.size(); ++i){
        if(s[i] == '}' || s[i] == ')' || s[i] == ']' || s[i] == '{' || s[i] == '(' || s[i] == '['){
            if(st.empty()){
                if(s[i] == '}' || s[i] == ')' || s[i] == ']'){
                    cout << i + 1;
                    return 0;
                }else{
                    st.push(i);
                }
            }else{
                if(s[i] == '{' || s[i] == '(' || s[i] == '[')
                    st.push(i);
                else{
                    if(s[i] == ')' && s[st.top()] == '('){
                        st.pop();
                    }else if(s[i] == ']' && s[st.top()] == '['){
                        st.pop();
                    }else if(s[i] == '}' && s[st.top()] == '{'){
                        st.pop();
                    }else{
                        cout << i + 1;
                        return 0;
                    }
                }
            }
        }
    }

    if(st.empty()){
        cout << "Success";
        return 0;
    }

    int pos = -1;
    while(!st.empty()){
        pos = st.top();
        st.pop();
    }


    cout << pos + 1;
    return 0;
}
