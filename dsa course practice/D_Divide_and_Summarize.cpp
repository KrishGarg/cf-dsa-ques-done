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
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
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

void findSums(vll& a, ll l, ll r, set<ll>& posSums, vll& prefSums,
              set<pair<ll, ll>>& visited) {
  // [l, r)
  if (l >= r) return;
  if (visited.find({l, r}) != visited.end()) return;
  posSums.insert(prefSums[r] - prefSums[l]);
  visited.insert({l, r});
  ll pivot = (a[l] + a[r - 1]) / 2;
  ll idx = upper_bound(all(a), pivot) - a.begin();

  findSums(a, l, idx, posSums, prefSums, visited);
  findSums(a, idx, r, posSums, prefSums, visited);
}

void solve() {
  ll n, q;
  cin >> n >> q;
  vll a(n);
  tin0(a, n);
  sort(all(a));

  vll prefSums(n + 1, 0);
  fu(i, 0, n - 1) {
    prefSums[i + 1] = prefSums[i] + a[i];  // prefSums[i] = a[i-1] + .. a[0]
  }
  set<ll> posSums;
  set<pair<ll, ll>> visited;
  findSums(a, 0, n, posSums, prefSums, visited);

  while (q--) {
    ll s;
    cin >> s;

    if (posSums.find(s) != posSums.end())
      yes;
    else
      no;
  }
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