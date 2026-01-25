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

ll dist(ll x1, ll y1, ll x2, ll y2) { return abs(x1 - x2) + abs(y1 - y2); }

void solve() {
  ll n, ax, ay, bx, by;
  cin >> n >> ax >> ay >> bx >> by;
  vll xs(n), ys(n);

  tin0(xs, n);
  tin0(ys, n);

  map<ll, pll, greater<ll>> minmaxatX;
  fu(i, 0, n - 1) {
    if (minmaxatX.find(xs[i]) == minmaxatX.end()) {
      minmaxatX[xs[i]].f = ys[i];
      minmaxatX[xs[i]].s = ys[i];
    } else {
      minmaxatX[xs[i]].f = min(ys[i], minmaxatX[xs[i]].f);
      minmaxatX[xs[i]].s = max(ys[i], minmaxatX[xs[i]].s);
    }
  }

  minmaxatX[bx] = {by, by};
  minmaxatX[ax] = {ay, ay};

  pll lastState = {0, 0};
  ll lastX = bx;
  for (auto p : minmaxatX) {
    ll x = p.f;
    pll atX = p.s;
    pll atlastX = minmaxatX[lastX];

    lastState = {
        min(dist(x, atX.f, lastX, atlastX.f) +
                dist(lastX, atlastX.f, lastX, atlastX.s) + lastState.s,
            dist(x, atX.f, lastX, atlastX.s) +
                dist(lastX, atlastX.f, lastX, atlastX.s) + lastState.f),

        min(dist(x, atX.s, lastX, atlastX.f) +
                dist(lastX, atlastX.f, lastX, atlastX.s) + lastState.s,
            dist(x, atX.s, lastX, atlastX.s) +
                dist(lastX, atlastX.f, lastX, atlastX.s) + lastState.f)};
    lastX = x;
  }

  cout << lastState.f << endl;
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