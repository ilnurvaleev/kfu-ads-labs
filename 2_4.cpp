#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;


int main() {
    int n;
    cin >> n;

    stack<int> mx;
    for(int i = 0 ; i < n; ++i){
        string s;
        cin >> s;

        if(s == "push"){
            int x;
            cin >> x;

            if(mx.empty())
                mx.push(x);
            else
                mx.push(max(mx.top(), x));
        }else if(s == "pop"){
            mx.pop();
        }else if(s == "max"){
            cout << mx.top() << endl;
        }
    }
    return 0;
}

