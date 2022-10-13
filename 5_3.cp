#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MOD = 2286661337;
const ll p = 239;

int main(){
    string s, q;
    cin >> s;
    cin >> q;

    vector<ll> powP(1 +max(s.size(), q.size()), 1);
    for(int i = 1; i < powP.size(); ++i)
        powP[i] = ((powP[i-1] * p) % MOD + MOD) % MOD;

    ll s1 = 0;
    for(int i = 0; i < s.size(); ++i)
        s1 = ((s1 + (s[i] - 'A' + 1) * powP[i]) % MOD + MOD) % MOD;

    vector<ll> h(q.size(), 0);
    h[0] = (q[0] - 'A' + 1);
    for(int i = 1; i < q.size(); ++i)
        h[i] = ((h[i-1] + (q[i] - 'A' + 1) * powP[i]) %  MOD + MOD) % MOD;

    if(h[s.size() - 1] == s1){
        cout << 0;
    }
    
    for(int i = 0; i + s.size() < q.size(); ++i){
        if((h[i + s.size()] - h[i] + MOD) % MOD == (s1 * powP[i+1]) % MOD)
            cout << ' ' << i+1 << ' ';
    }
    return 0;
}
