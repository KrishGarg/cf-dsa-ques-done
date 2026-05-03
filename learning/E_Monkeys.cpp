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

  vvll lr(n + 1);
  fu(i, 1, n) {
    ll u, v;
    cin >> u >> v;
    lr[i] = {u, v};
  }
  vpll times(m);
  fu(i, 0, m - 1) {
    ll u, v;
    cin >> u >> v;
    times[i] = {u, v};
  }

  vvll lrc = lr;
  fu(i, 0, m - 1) { lrc[times[i].f][times[i].s - 1] = -1; }

  vvll adj(n + 1);
  fu(i, 1, n) {
    if (lrc[i][0] != -1) {
      adj[i].pb(lrc[i][0]);
      adj[lrc[i][0]].pb(i);
    }
    if (lrc[i][1] != -1) {
      adj[i].pb(lrc[i][1]);
      adj[lrc[i][1]].pb(i);
    }
  }

  vll ans(n + 1, -1);
  vector<bool> inTree(n + 1, false);

  auto dfs = [&](auto& self, ll u, ll t) -> void {
    inTree[u] = true;
    ans[u] = t;
    for (ll v : adj[u]) {
      if (!inTree[v]) {
        self(self, v, t);
      }
    }
  };

  dfs(dfs, 1, -1);
  fd(t, m - 1, 0) {
    auto [u, h] = times[t];
    ll v = lr[u][h - 1];

    adj[v].pb(u);
    adj[u].pb(v);

    if (inTree[u] && !inTree[v]) {
      dfs(dfs, v, t);
    }
    if (!inTree[u] && inTree[v]) {
      dfs(dfs, u, t);
    }
  }

  fu(i, 1, n) cout << ans[i] << endl;
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