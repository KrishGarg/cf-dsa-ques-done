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

struct DSU {
  // DSU dsu(n);
  vll p;
  vll sz;

  DSU(ll n) {
    p = vll(n + 1);
    sz = vll(n + 1, 1);
    fu(i, 1, n) { p[i] = i; }
  }

  ll get(ll x) {
    if (p[x] == x) return x;
    return p[x] = get(p[x]);
  }

  void uni(ll x, ll y) {
    x = get(x);
    y = get(y);
    if (x == y) return;
    if (sz[x] < sz[y]) swap(x, y);
    sz[x] += sz[y];
    p[y] = x;
  }

  bool same(ll u, ll v) { return get(u) == get(v); }
};

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

const ll MOD = 998244353;
const ll MAXN = 3e6 + 1;

ll fact[MAXN];
ll invFact[MAXN];

void precomp() {
  fact[0] = 1;
  invFact[0] = 1;

  fu(i, 1, MAXN - 1) { fact[i] = (i * fact[i - 1]) % MOD; }
  invFact[MAXN - 1] = inv(fact[MAXN - 1], MOD);
  fd(i, MAXN - 2, 1) { invFact[i] = (invFact[i + 1] * (i + 1)) % MOD; }
}

ll ncr(ll n, ll r) {
  if (r < 0 || r > n || n < 0) return 0;
  return fact[n] * invFact[r] % MOD * invFact[n - r] % MOD;
}

void solve() {
  ll x1, x2, x3;
  cin >> x1 >> x2 >> x3;

  if (x1 == 0) {
    cout << ncr(x2 + x3, x2) << endl;
    return;
  }

  if (x3 == 0) {
    cout << ncr(x1 + x2, x2) << endl;
  }

  if (x2 == 0) {
    cout << 0 << endl;
    return;
  }

  ll ans = 0;
  ll lt = min(x1, x2 + 1);

  fu(k, 1, lt) {
    ll tt =
        ncr(x2 + 1, k) * ncr(x1 - 1, k - 1) % MOD * ncr(x2 + x3 - k, x3) % MOD;
    ans = (ans + tt) % MOD;
  }

  cout << ans << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(0);

  precomp();
  ll t = 1;
  // cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}