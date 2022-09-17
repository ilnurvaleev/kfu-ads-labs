#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

vector<vector<int>> ans;
void SiftUp(vector<int>& q, int node){
    while(node != 1 && q[node] < q[node / 2]){
        swap(q[node], q[node / 2]);
        ans.push_back({node-1, node/2 - 1});
        node /= 2;
    }
}


void SiftDown(vector<int>& q, int node){
    while (node * 2 < q.size()){
        int left = node * 2;
        int right = node * 2 + 1;

        int swp = -1;
        if(right < q.size() && q[right] < q[left])
            swp = right;
        else
            swp = left;

        if(q[node] < q[swp])
            break;

        ans.push_back({swp-1, node-1});
        swap(q[node], q[swp]);
        node = swp;
    }
}


int main() {
    int n;
    cin >> n;
    vector<int> a(n+1);
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    for(int i = n; i >= 1; --i){
        SiftDown(   a, i);
    }

    cout << ans.size() << endl;
    for(int i = 0; i < ans.size(); ++i){
        cout << ans[i][0] << ' ' << ans[i][1] << endl;
    }
    return 0;
}

