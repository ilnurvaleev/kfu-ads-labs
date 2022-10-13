#include <bits/stdc++.h>

using namespace std;

typedef long long ll;


int main(){
    int n;
    cin >> n;

    unordered_map<int, string> a;
    for(int i = 0; i < n; ++i){
        string s;
        cin >> s;

        if(s == "add"){
            int number;
            string name;
            cin >> number >> name;
            a[number] = name;
        }else if(s == "find"){
            int number;
            cin >> number;
            if(a.find(number) == a.end())
                cout << "not found";
            else
                cout << a[number];
            cout << endl;
        }else if(s == "del"){
            int number;
            cin >> number;
            a.erase(number);
        }
    }
    return 0;
}
