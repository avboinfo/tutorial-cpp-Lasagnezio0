// NOTE: it is recommended to use this even if you don't understand the following code.

#include <fstream>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main() {
    // uncomment the two following lines if you want to read/write from files
    ifstream cin("input.txt");
    ofstream cout("output.txt");

    int N;
    cin >> N;

    vector<int> P(N);
    for (int i = 0; i < N; ++i) cin >> P[i];

    int min_index = 0, m = 0, K = 0, cont = 0, cont2 = 0;

    if(P.size() == 1){
        K = 0;
        cout << K << endl;
        return 0;
    }
    for(int i = 0; i < N - 1; i++){
        if(P[i] < P[i + 1]) m++;
    }
    if(m == N - 1){
        cout << 0 << endl;
        return 0;
    }

    for(int i = 0; i < N - 1; i++) if(P[i] < P[min_index]) min_index = i;

    for(int i = min_index; i < N - 1; i++){
        if(P[i] < P[i + 1]){
            cont++;
            K++;

        }
    }

    if(cont == N - min_index - 1){
        for(int i = 0; i < min_index; i++){
            if(P[i] > P[i + 1]){
                cont2++;
                K++;
            }
        }
    }else{
        K = -1;
    }   
    cout << K << endl;

    return 0;
}
