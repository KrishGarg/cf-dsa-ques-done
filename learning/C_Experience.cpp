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

struct DSU {
  vll p;
  vll sz;
  vll add_to_root;
  vll delta;

  DSU(ll n) {
    p = vll(n + 1);
    sz = vll(n + 1, 1);
    add_to_root = vll(n + 1, 0);
    delta = vll(n + 1, 0);

    fu(i, 1, n) { p[i] = i; }
  }

  ll get(ll x) {
    if (p[x] == x) return x;
    ll par = p[x];
    p[x] = get(p[x]);
    delta[x] += delta[par];
    return p[x];
  }

  void join(ll x, ll y) {
    x = get(x);
    y = get(y);

    if (x == y) return;
    if (sz[x] < sz[y]) swap(x, y);

    sz[x] += sz[y];
    p[y] = x;
    delta[y] = add_to_root[y] - add_to_root[x];
  }

  void add(ll x, ll v) { add_to_root[get(x)] += v; }

  ll experience(ll x) {
    ll root = get(x);
    return add_to_root[root] + delta[x];
  }
};

void solve() {
  ll n, m;
  cin >> n >> m;

  DSU dsu(n);

  fu(i, 0, m - 1) {
    str q;
    cin >> q;

    ll x, y;

    if (q == "join") {
      cin >> x >> y;
      dsu.join(x, y);
    } else if (q == "add") {
      ll v;
      cin >> x >> v;
      dsu.add(x, v);
    } else {
      cin >> x;
      cout << dsu.experience(x) << '\n';
    }
  }
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