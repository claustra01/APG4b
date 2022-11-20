#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N,ave=0;
  cin >> N;
  vector<int> A(N);
  for (int i=0; i<N; i++) {
    cin >> A[i];
    ave += A[i];
  }
  ave /= N;
  for (int i=0; i<N; i++) cout << abs(A[i]-ave) << endl;
}