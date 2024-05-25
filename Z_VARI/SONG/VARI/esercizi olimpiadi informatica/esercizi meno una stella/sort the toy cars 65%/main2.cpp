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

    int min_index = 0,max_index = 0, m = 0, K = 0, cont = 0, cont2 = 0;

    //se il vettore è grande uno allora non ce bisogno di spostamenti
    if(P.size() == 1){
        K = 0;
        cout << K << endl;
        return 0;
    }
    
    //se il vettore è gia ordinato non ce bisogno di spostamenti
    if(is_sorted(P.begin(), P.end())){
        K = 0;
        cout << K << endl;
        return 0;     
    }

    //trovo il valore minore
    if (P.size() > 1) {
        for (int i = 1; i < P.size(); i++) {
            if (P[i] < P[min_index]) {
                min_index = i;
            }
        }
    }else{
        if(P[0] < P[1]) min_index = P[0];
        else min_index = P[1];
    }

    //trovo il valore massimo
    if (P.size() > 1) {
        for (int i = 1; i < P.size(); i++) {
            if (P[i] > P[max_index]) {
                max_index = i;
            }
        }
    }else{
        if(P[0] > P[1]) max_index = P[0];
        else max_index = P[1];
    }


    for(int i = max_index; i < N - 1; ++i){
        if(P[i] < P[i + 1]){
            cont++;
            K++;

        }
    }

    if(cont == N - min_index - 1){
        for(int i = 0; i < min_index; ++i){
            if(P[i] > P[i + 1]){
                cont2++;
                K++;
            }
        }
    }else{
        K = -1;
    }
    //se è ordinato all inverso
    if(P.back() == P[max_index] && P[0] == P[min_index]) K = -1;
    //se va tutto bene
    if(P[0] < P[N - 1]) K = -1;   
    cout << K << endl;

    return 0;
}
