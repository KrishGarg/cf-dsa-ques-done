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

// bool sorter(pair<ll, pll> p1, pair<ll, pll> p2) {
//   if (p1.s.f == p2.s.f) return p1.s.s > p2.s.s;
//   return p1.s.f < p2.s.f;
// }

void solve() {
  ll n;
  cin >> n;

  vpll ab(n);
  fu(i, 0, n - 1) {
    ab[i].f = i + 1;
    cin >> ab[i].f >> ab[i].s;
  }

  // sort(all(ab), sorter);

  ll l = 0, r = n;
  ll ans = -1;
  while (l <= r) {
    ll x = (l + r) / 2;
    ll j = 0;
    ll peopleSat = 0;
    fu(i, 1, x) {
      for (; j < n; j++) {
        if (ab[j].f >= x - i && ab[j].s >= i - 1) {
          peopleSat++;
          j++;
          break;
        }
      }
    }

    if (peopleSat != x) {
      r = x - 1;
    } else {
      ans = x;
      l = x + 1;
    }
  }

  cout << ans << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(0);

  ll t;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}