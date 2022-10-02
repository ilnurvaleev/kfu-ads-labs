#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<int> parent;
vector<int> w;


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

    if(w[x] < w[y])
        swap(x, y);

    w[x] += w[y];
    parent[y] = x;
}

int main(){
    int n, e, d;
    cin >> n >> e >> d;

    parent.assign(n, 0);
    w.assign(n, 1);

    for(int i = 0; i < n; ++i)
        parent[i] = i;

    for(int i = 0; i < e; ++i){
        int x, y;
        cin >> x >> y;
        --x, --y;
        unionSet(x, y);
    }

    bool ans = true;
    for(int i = 0; i < d; ++i){
        int x, y;
        cin >> x >> y;
        --x, --y;

        if(get(x) == get(y))
            ans = false;
    }
    cout << ans;
    return 0;
}
