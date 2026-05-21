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

ll getPotsForColor(ll roses, ll k) {
  if (roses == 0) return 0;
  return roses + (roses + k - 1) / k - 1;
}

void solve() {
  ll n, m, k;
  cin >> n >> m >> k;

  vll a(n);
  ll totAvailRoses = 0;
  fu(i, 0, n - 1) {
    cin >> a[i];
    totAvailRoses += a[i];
  }

  sort(all(a), greater<>());

  auto check = [&](ll target) -> bool {
    ll roseLeft = target;
    ll potsNeeded = 0;
    bool firstCol = true;

    for (ll supply : a) {
      if (roseLeft == 0) break;

      ll take = min(supply, roseLeft);
      roseLeft -= take;

      ll potsCnt = getPotsForColor(take, k);
      potsNeeded += potsCnt;

      if (!firstCol) {
        potsNeeded += 1;
      }
      firstCol = false;

      if (potsNeeded > m) return false;
    }

    return roseLeft == 0 && potsNeeded <= m;
  };

  ll low = 0, high = min(totAvailRoses, m);
  ll ans = 0;

  while (low <= high) {
    ll mid = low + (high - low) / 2;
    if (check(mid)) {
      ans = mid;
      low = mid + 1;
    } else {
      high = mid - 1;
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