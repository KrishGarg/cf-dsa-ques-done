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

void merger(vector<pll>& inp, ll l, ll mid, ll r) {
  ll n1 = mid - l + 1;
  ll n2 = r - mid;

  vpll L(n1), R(n2);
  for (ll i = 0; i < n1; i++) {
    L[i] = inp[i + l];
  }

  for (ll i = 0; i < n2; i++) {
    R[i] = inp[mid + i + 1];
  }

  ll i = 0, j = 0, k = l;
  while (i < n1 && j < n2) {
    if (L[i].second <= R[j].second) {
      inp[k++] = L[i++];
    } else {
      inp[k++] = R[j++];
    }
  }

  while (i < n1) {
    inp[k++] = L[i++];
  }

  while (j < n2) {
    inp[k++] = R[j++];
  }
}

ll greetings(vector<pll>& inps, ll l, ll r) {
  if (l >= r) return 0;

  ll mid = l + (r - l) / 2;
  ll greets = greetings(inps, l, mid) + greetings(inps, mid + 1, r);

  ll i = l;
  for (ll j = mid + 1; j <= r; j++) {
    while (i <= mid && inps[i].second < inps[j].second) i++;
    greets += mid - i + 1;
  }
  merger(inps, l, mid, r);
  return greets;
}

ll solver(int n, vector<ll>& a, vector<ll>& b) {
  vpll inp(n);
  for (ll i = 0; i < n; i++) {
    inp[i] = {a[i], b[i]};
  }

  sort(inp.begin(), inp.end(),
       [](pll p1, pll p2) { return p1.first < p2.first; });

  return greetings(inp, 0, n - 1);
}

void solve() {
  ll n;
  cin >> n;
  vll a(n), b(n);
  fu(i, 0, n - 1) { cin >> a[i] >> b[i]; }

  cout << solver(n, a, b) << endl;
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