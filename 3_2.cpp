#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <queue>


using namespace std;



int main() {
    int n, m;
    cin >> n >> m;

    vector<long long> tasks(m);
    for(int i = 0; i < m; ++i)
        cin >> tasks[i];

    priority_queue<vector<long long>> q;
    for(int i = 0; i < n; ++i)
        q.push({0, -i});


    for(int i = 0; i < m; ++i){
        vector<long long> top = q.top();
        q.pop();

        cout << -top[1] << ' ' << -top[0] << endl;

        top[0] -= tasks[i];
        q.push(top);
    }
    return 0;
}

