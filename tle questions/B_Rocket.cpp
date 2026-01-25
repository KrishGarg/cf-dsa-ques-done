#include <bits/stdc++.h>
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

ll query(ll y) {
  cout << y << endl;
  ll s;
  cin >> s;

  if (s == -2) exit(0);
  return s;
}

void solve() {
  ll m, n;
  cin >> m >> n;

  vll p(n, -1);
  // first n queries to determine the sequence
  // send y = 1, if we get -1 then its incorrect (0), 1 then correct (1)
  fu(i, 0, n - 1) {
    ll q = query(1);
    if (q == -1)
      p[i] = 0;
    else if (q == 1)
      p[i] = 1;
    else
      return;  // x = 1 then res = 0
  }

  ll l = 1, r = m;
  ll cnt = 0;
  while (l <= r) {
    ll mid = l + (r - l) / 2;
    ll q = query(mid);
    if (q == 0) return;
    if (p[cnt] == 0) q *= -1;
    cnt = (cnt + 1) % n;

    if (q == 1) {
      l = mid + 1;
    } else {
      r = mid - 1;
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