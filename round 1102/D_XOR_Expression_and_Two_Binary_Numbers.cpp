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

typedef __gnu_pbds::tree<ll, __gnu_pbds::null_type, less<ll>,
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

const ll MAXN = 10000005;
ll spf[MAXN];
void computeSPF() {
  for (ll i = 1; i < MAXN; i++) spf[i] = i;
  for (ll i = 2; i * i < MAXN; i++) {
    if (spf[i] == i) {
      for (ll j = i * i; j < MAXN; j += i) {
        if (spf[j] == j) spf[j] = i;
      }
    }
  }
}

vector<ll> factorize(ll x) {
  vector<ll> ret;
  while (x != 1) {
    ret.push_back(spf[x]);
    x = x / spf[x];
  }
  return ret;
}

struct SegTree {  // sumTree
  ll sz;
  vll sums;

  SegTree(ll n) {
    sz = 1;
    while (sz < n) sz *= 2;

    sums = vll(2 * sz, 0LL);
  }

  SegTree(vll& a) : SegTree(a.size()) { build(a); }

  ll left(ll x) { return 2 * x + 1; }

  ll right(ll x) { return 2 * x + 2; }

  ll parent(ll x) {
    if (x == 0) return -1;
    return (x - 1) / 2;
  }

  void build(vll& a, ll x, ll lx, ll rx) {
    if (rx - lx == 1) {
      if (lx < (ll)a.size()) sums[x] = a[lx];
      return;
    }

    ll m = lx + (rx - lx) / 2;
    build(a, left(x), lx, m);
    build(a, right(x), m, rx);

    sums[x] = sums[left(x)] + sums[right(x)];
  }

  void build(vll& a) { build(a, 0, 0, sz); }

  void set(ll i, ll v, ll x, ll lx, ll rx) {
    if (rx - lx == 1) {
      sums[x] = v;
      return;
    }

    ll m = lx + (rx - lx) / 2;
    if (i < m) {
      set(i, v, left(x), lx, m);
    } else {
      set(i, v, right(x), m, rx);
    }

    sums[x] = sums[left(x)] + sums[right(x)];
  }

  void set(ll i, ll v) { set(i, v, 0, 0, sz); }

  ll query(ll l, ll r, ll x, ll lx, ll rx) {
    if (l >= rx || r <= lx) return 0;
    if (lx >= l && rx <= r) return sums[x];

    ll m = lx + (rx - lx) / 2;
    ll s1 = query(l, r, left(x), lx, m);
    ll s2 = query(l, r, right(x), m, rx);
    return s1 + s2;
  }

  ll query(ll l, ll r) { return query(l, r, 0, 0, sz); }
};

void solve() {
  ll n, k;
  cin >> n >> k;

  str a1, alast;
  cin >> a1 >> alast;

  ll a1z = 0, a1o = 0, alastz = 0, alasto = 0, amidz = 0, amido = 0;

  fu(i, 0, n - 1) {
    if (a1[i] == '1')
      a1o++;
    else
      a1z++;

    if (alast[i] == '1')
      alasto++;
    else
      alastz++;

    if (alast[i] != a1[i])
      amido++;
    else
      amidz++;
  }

  ll pa1 = a1z * a1o, pamid = amidz * amido, palast = alastz * alasto;

  ll ans;
  if (k & 1) {
    ans = (pa1 + palast + pamid) * (((1 << k) + 1) / 3);
  } else {
    ans = (pa1 + palast + pamid) * (((1 << k) - 1) / 3);
    ans += pa1 + palast;
  }

  cout << ans << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(0);

  ll t = 1;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}