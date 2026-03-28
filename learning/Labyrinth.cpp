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

  vector<vector<ch>> grid(n, vector<ch>(m));
  pll A, B;
  fu(i, 0, n - 1) {
    fu(j, 0, m - 1) {
      cin >> grid[i][j];
      if (grid[i][j] == 'A') A = {i, j};
      if (grid[i][j] == 'B') B = {i, j};
    }
  }

  auto valid = [&](ll x, ll y) {
    return x < n && y < m && x >= 0 && y >= 0 && grid[x][y] != '#';
  };

  queue<pll> q;
  vector<vector<pll>> prev(n, vector<pll>(m));
  vvll d(n, vll(m, LLONG_MAX));

  q.push(A);
  d[A.f][A.s] = 0;

  vpll ds = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
  while (!q.empty()) {
    auto& [x, y] = q.front();
    q.pop();

    fu(i, 0, 3) {
      auto& [dx, dy] = ds[i];
      ll nx = x + dx, ny = y + dy;
      if (!valid(nx, ny)) continue;
      if (d[x][y] + 1 < d[nx][ny]) {
        d[nx][ny] = d[x][y] + 1;
        prev[nx][ny] = {x, y};
        q.push({nx, ny});
      }
    }
  }

  if (d[B.f][B.s] == LLONG_MAX) {
    cout << "NO" << endl;
    return;
  }

  vector<ch> ans;
  pll cur = B;
  while (cur != A) {
    pll p = prev[cur.f][cur.s];
    if (p.f + 1 == cur.f)
      ans.pb('D');
    else if (p.f - 1 == cur.f)
      ans.pb('U');
    else if (p.s + 1 == cur.s)
      ans.pb('R');
    else
      ans.pb('L');

    cur = p;
  }
  reverse(all(ans));
  cout << "YES" << endl;
  cout << ans.size() << endl;
  fu(i, 0, ans.size() - 1) { cout << ans[i]; }
  cout << endl;
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