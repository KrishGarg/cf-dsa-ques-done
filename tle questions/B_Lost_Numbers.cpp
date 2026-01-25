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

ll query(ll l, ll r) {
  cout << "? " << l << " " << r << endl;
  ll s;
  cin >> s;
  return s;
}

ll commonFromPairs(pll p1, pll p2) {
  if (p1.f == p2.f || p1.f == p2.s)
    return p1.f;
  else if (p1.s == p2.f || p1.s == p2.s)
    return p1.s;
  return -1;
}

ll notinPair(pll p, ll a) {
  if (p.f == a)
    return p.s;
  else
    return p.f;
}

void solve() {
  map<ll, pll> facts;
  vll special = {4, 8, 15, 16, 23, 42};

  fu(i, 0, 5) {
    fu(j, i + 1, 5) {
      facts.insert(make_pair(special[i] * special[j],
                             make_pair(special[i], special[j])));
    }
  }

  pll potAB, potCD, potBC, potDE;
  potAB = facts.at(query(1, 2));
  potBC = facts.at(query(2, 3));
  potCD = facts.at(query(3, 4));
  potDE = facts.at(query(4, 5));

  vll ans(6, -1);
  ans[1] = commonFromPairs(potAB, potBC);
  ans[2] = commonFromPairs(potCD, potBC);
  ans[3] = commonFromPairs(potCD, potDE);

  ans[0] = notinPair(potAB, ans[1]);
  ans[4] = notinPair(potDE, ans[3]);

  for (ll s : special) {
    bool tick = false;
    fu(i, 0, 4) {
      if (ans[i] == s) {
        tick = true;
        break;
      }
    }
    if (!tick) {
      ans[5] = s;
      break;
    }
  }

  cout << "! ";
  fu(i, 0, 5) { cout << ans[i] << " "; }
  cout << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(0);

  // ll t;
  // cin >> t;
  // while (t--) {
  //   solve();
  // }

  solve();

  return 0;
}