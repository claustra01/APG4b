#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  map<int, int> data;
  for (int i=0; i<n; i++) {
    int x;
    cin >> x;
    data[x]++;
  }
  
  pair<int, int> ans;
  ans.second = 0;
  for (auto p : data) if (p.second > ans.second) ans = p;
  cout << ans.first << " " << ans.second << endl;
  
}