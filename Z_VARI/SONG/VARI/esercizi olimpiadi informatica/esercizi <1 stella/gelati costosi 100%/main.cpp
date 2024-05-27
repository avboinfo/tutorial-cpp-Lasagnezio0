#include <cassert>
#include <fstream>
#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

int presta(int N, int C, vector<int> P){
    sort(P.begin(), P.end(), greater<int>());
    int amici_necessari = 0, left_idx = 0;
    for(int i = 0; C > 0; i++){
        C -= P[i];
        amici_necessari++;
    }
    return amici_necessari;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

    ifstream cin("input.txt");
    ofstream cout("output.txt");
  int N, C;
  assert(cin >> N);
  assert(cin >> C);

  vector<int> P(N);
  for (int& p : P) {
    assert(cin >> p);
  }
  cout << presta(N, C, move(P)) << "\n";
}
