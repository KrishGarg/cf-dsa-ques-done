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

ll getMaxSubArrSum(vll& a) {
  ll varSum = 0, ans = 0;
  for (ll k : a) {
    varSum = max(k, varSum + k);
    ans = max(varSum, ans);
  }
  return ans;
}

void solve() {
  ll n;
  cin >> n;
  vll a(n);
  tin0(a, n);

  ll summ = 0;
  for (ll i = 0; i < n; i += 2) {
    summ += a[i];
  }
  vll v1, v2;

  for (ll i = 0; i < n - 1; i += 2) {
    v1.pb(a[i + 1] - a[i]);
  }

  for (ll i = 1; i < n - 1; i += 2) {
    v2.pb(a[i] - a[i + 1]);
  }
  ll max_gain = 0;
  if (!v1.empty()) max_gain = max(max_gain, getMaxSubArrSum(v1));
  if (!v2.empty()) max_gain = max(max_gain, getMaxSubArrSum(v2));

  cout << summ + max_gain << endl;
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