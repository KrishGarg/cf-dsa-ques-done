#include <bits/stdc++.h>
using namespace std;

vector<double> dp(1000001, 1);

void solve() {
  int n;
  cin >> n;
  cout << floor(dp[n]) << endl;
}

int main() {
  int t;
  cin >> t;
  dp[1] = 1;
  double sum = 1;
  for (int i = 2; i < 1000001; i++) {
    sum += 1.0 / i;
    dp[i] = sum;
  }

  while (t--) {
    solve();
  }
  return 0;
}