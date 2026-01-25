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

void solve() {
  ll n, m, k;
  cin >> n >> m >> k;

  // ll l = 1, r = n;
  // ll ans = -1;

  // while(l <= r) {
  //   ll x = l + (r-l)/2;

  //   ll distLeft = x - 1, distRight = n - x;
  //   ll le = k -
  // }

  ll l = k - 1, r = k + 1;
  ll ans = 1;
  ll chance = 1;
  while (l >= 1 || r <= n) {
    if (l >= 1 && chance == 1) {
      if (m >= 1) {
        ans++;
        chance = 0 ? r <= n : 1;
        l--;
        m--;
        continue;
      } else {
        break;
      }
    }

    if (r <= n && chance == 0) {
      if (m >= 1) {
        ans++;
        chance = 1 ? l >= 1 : 0;
        r++;
        m--;
        continue;
      } else {
        break;
      }
    }
    break;
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