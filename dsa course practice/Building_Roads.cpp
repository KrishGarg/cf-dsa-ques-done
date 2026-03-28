#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;

using dbl = long double;
using ll = long long;
using str = string;
using ch = char;
using vll = vector<ll>;
using vdbl = vector<dbl>;
using vvll = vector<vll>;
using pll = pair<ll, ll>;
using mpll = map<ll, ll>;
using vpll = vector<pll>;
#define eb emplace_back
#define pb push_back
#define fo(i, k, n) \
  for (ll i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
#define fu(i, k, n) for (ll i = k; i <= n; i++)
#define fd(i, k, n) for (ll i = k; i >= n; i--)
#define tin0(a, n) fo(i, 0, n) cin >> a[i]
#define tin1(a, n) fu(i, 1, n) cin >> a[i]
#define all(v) v.begin(), v.end()
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define f first
#define s second

typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, less<int>,
                         __gnu_pbds::rb_tree_tag,
                         __gnu_pbds::tree_order_statistics_node_update>
    ordered_set;

ll pow(ll a, ll b) {
  ll res = 1;
  while (b > 0) {
    if (b & 1) res *= a;
    a *= a;
    b >>= 1;
  }
  return res;
}

ll modpow(ll a, ll b, ll m) {
  ll res = 1;
  while (b) {
    if (b & 1) res = (res * a) % m;
    a = (a * a) % m;
    b >>= 1;
  }
  return res;
}

ll inv(ll a, ll m) { return modpow(a, m - 2, m); }

void solve() {
  ll n, m;
  cin >> n >> m;

  vvll adj(n + 1);
  fu(i, 1, m) {
    ll u, v;
    cin >> u >> v;
    adj[u].eb(v);
    adj[v].eb(u);
  }

  vll visited(n + 1, 0);
  vll conComps;
  fu(i, 1, n) {
    if (visited[i]) continue;

    visited[i] = 1;
    conComps.eb(i);
    queue<ll> q;
    q.push(i);
    while (!q.empty()) {
      ll top = q.front();
      q.pop();
      for (ll nei : adj[top]) {
        if (!visited[nei]) {
          visited[nei] = 1;
          q.push(nei);
        }
      }
    }
  }

  ll k = conComps.size() - 1;
  cout << k << endl;
  fu(i, 0, k - 1) { cout << conComps[i] << " " << conComps[i + 1] << endl; }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(0);

  // ll t;
  // cin >> t;
  // while (t--) {
  solve();
  // }

  return 0;
}