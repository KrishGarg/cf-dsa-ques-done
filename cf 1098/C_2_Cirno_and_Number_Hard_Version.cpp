#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;

using dbl = long double;
using ll = long long;
using ull = unsigned long long;
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

void solve() {
  str a;
  ll n;
  cin >> a >> n;

  vll d(n);
  tin0(d, n);

  if (n == 1 && d[0] == 0)  // only zeroes
  {
    cout << a << endl;
    return;
  }

  ull aval = stoull(a);
  ull ans = -1;

  auto update = [&](str cand_str) {
    if (cand_str.empty()) return;
    ull cand = stoull(cand_str);
    ull diff = (cand > aval) ? (cand - aval) : (aval - cand);
    if (ans == -1 || diff < ans) {
      ans = diff;
    }
  };

  ch d_min = d.front() + '0';
  ch d_max = d.back() + '0';

  ch d_min_nz = -1;
  for (ll x : d) {
    if (x > 0) {
      d_min_nz = x + '0';
      break;
    }
  }

  if (a.size() > 1) {
    update(str(a.size() - 1, d_max));
  }

  if (d_min_nz != -1) {
    update(str(1, d_min_nz) + str(a.size(), d_min));
  }

  fu(i, 0, (ll)a.size() - 1) {
    for (ll x : d) {
      char c = x + '0';

      if (i == 0 && c == '0' && a.size() > 1) continue;

      if (c < a[i]) {
        update(a.substr(0, i) + c + str(a.size() - 1 - i, d_max));
      } else if (c > a[i]) {
        update(a.substr(0, i) + c + str(a.size() - 1 - i, d_min));
      }
    }

    bool match = false;
    for (ll x : d) {
      if (x + '0' == a[i]) {
        match = true;
        break;
      }
    }

    if (!match) break;

    if (i == a.size() - 1) {
      update(a);
    }
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