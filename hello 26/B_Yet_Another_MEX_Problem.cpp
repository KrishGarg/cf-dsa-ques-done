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
  ll n, k;
  cin >> n >> k;

  vll a(n);
  tin0(a, n);

  // map<ll, ll, greater<>> freq;
  // fo(i, 0, n) { freq[a[i]]++; }

  // ll toRemove = n - k + 1;
  // for (auto i = freq.begin(); i != freq.end(); i++) {
  //   if (i->s > 1) {
  //     // cout << toRemove << " " << i->f << " " << i->s << endl;
  //     if (toRemove - (i->s - 1) >= 0) {
  //       toRemove -= i->s - 1;
  //       i->s = 1;
  //     } else {
  //       i->s -= toRemove;
  //       toRemove = 0;
  //       break;
  //     }
  //   }
  // }

  // if (toRemove > 0) {
  //   for (auto i = freq.begin(); i != freq.end(); i++) {
  //     i->s = 0;
  //     toRemove--;
  //     if (toRemove <= 0) break;
  //   }
  // }

  // ll mex = 0;
  // for (auto i = freq.rbegin(); i != freq.rend(); i++) {
  //   // cout << i->first << " " << i->second << endl;
  //   if (i->s > 0 && i->f == mex)
  //     mex++;
  //   else
  //     break;
  // }
  // cout << mex << endl;

  sort(all(a));
  ll mex = 0;
  fu(i, 0, n - 1) {
    if (a[i] == mex) {
      mex++;
    }
  }

  cout << min(k - 1, mex) << endl;
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