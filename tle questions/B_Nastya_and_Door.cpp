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

  vll a(n + 1);
  tin1(a, n);

  ll peaks = 0, ansPeaks = 0, ansL = 1;
  fu(i, 2, k - 1) {
    // initial window
    if (a[i] > a[i - 1] && a[i] > a[i + 1]) {
      peaks++;
    }
  }
  ansPeaks = peaks;

  fu(l, 2, n - k + 1) {
    if (a[l] > a[l - 1] && a[l] > a[l + 1]) {
      peaks--;
    }
    ll r = l + k - 1;
    if (a[r - 1] > a[r - 2] && a[r - 1] > a[r]) {
      peaks++;
    }

    if (peaks > ansPeaks) {
      ansPeaks = peaks;
      ansL = l;
    }
  }

  cout << (ansPeaks + 1) << " " << ansL << endl;
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