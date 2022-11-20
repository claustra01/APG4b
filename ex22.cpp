#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  pair<int, int> p[n];
  for (int i=0; i<n; i++) cin >> p[i].first >> p[i].second;
  
  for (int i=0; i<n-1; i++) {
    for (int j=i; j<n; j++) {
      if (p[i].second > p[j].second) swap(p[i], p[j]);
    }
  }
  
  for (int i=0; i<n; i++) cout << p[i].first << " " << p[i].second << endl;;
  
}