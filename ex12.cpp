#include <bits/stdc++.h>
using namespace std;
 
int main() {
  string S;
  cin >> S;
  int n=1;
 
  // ここにプログラムを追記
  for (int i=0; i < (S.size()-1)/2; i++) {
  	if (S.at(i*2+1) == '+') n++;
    else if (S.at(i*2+1) == '-') n--;
  }
  
  cout << n << endl;
}