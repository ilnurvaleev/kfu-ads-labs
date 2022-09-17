#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

vector<vector<int>> graph;

int dfs(int node, int level = 1){

    int mx = level;
    for(int i = 0; i < graph[node].size(); ++i){
        int to = graph[node][i];

        mx = max(mx, dfs(to, level + 1));
    }
    return mx;
}

int main() {
    int n;
    cin >> n;

    graph.assign(n, {});
    vector<int> p(n);
    for(int i = 0; i < n; ++i)
        cin >> p[i];

    int root = -1;
    for(int i = 0; i < n; ++i){
        if(p[i] == -1)
            root = i;
    }

    for(int i = 0; i < n; ++i){
        if(p[i] == -1) continue;
        graph[p[i]].push_back(i);
    }

    cout << dfs(root);
    return 0;
}

