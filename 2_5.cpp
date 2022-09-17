#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;


int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; ++i)
        cin >> a[i];

    int m;
    cin >> m;
    deque<int> q;
    for(int i = 0; i < m; ++i){
        while (!q.empty() && a[q.back()] <= a[i])
            q.pop_back();

        while(!q.empty() && i - q.front() >= m)
            q.pop_front();

        q.push_back(i);
    }
    vector<int> ans;

    ans.push_back(a[q.front()]);
    for(int i = m; i < n; ++i){
        while (!q.empty() && a[q.back()] <= a[i])
            q.pop_back();

        while(!q.empty() && i - q.front() >= m)
            q.pop_front();

        q.push_back(i);
        ans.push_back(a[q.front()]);
    }

    for(int i = 0; i < ans.size(); ++i)
        cout << ans[i] << ' ';
    return 0;
}

