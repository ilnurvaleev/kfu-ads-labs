#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<int> parent;
vector<int> w;
int MaxW = 0;


ll get(ll node){
    if(parent[node] == node)
        return node;
    parent[node] = get(parent[node]);
    return parent[node];
}

void unionSet(ll x, ll y){
    x = get(x);
    y = get(y);

    if(x == y) return;

    w[x] += w[y];
    parent[y] = x;

    MaxW = max(MaxW, w[x]);
}

int main(){
    int n, m;
    cin >> n >> m;

    parent.assign(n, 0);
    w.assign(n, 1);

    for(int i = 0; i < n; ++i){
        int x;
        cin >> x;

        w[i] = x;
        parent[i] = i;

        MaxW = max(MaxW, x);
    }

    for(int i = 0; i < m; ++i){
         int x, y;
         cin >> x >> y;
         --x, --y;

        unionSet(x, y);
        cout << MaxW << endl;
    }
    return 0;
}
