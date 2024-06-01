// NOTE: it is recommended to use this even if you don't understand the following code.

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// input data
int K, N, R, T;
vector<int> S;

int main() {
	// uncomment the following lines if you want to read/write from files
	   ifstream cin("input.txt");
	   ofstream cout("output.txt");

    cin >> K;
    for (int j=0; j<K; j++) {
        cin >> N >> R >> T;
        S.resize(N);
        for (int i=0; i<N; i++)
            cin >> S[i];

        // insert your code here
        int max = R + T;
        int somma = 0;
        for(int i = 0; i < N; i++){
            somma += S[i];
        }
        somma /= N;
        if(somma > max){
            cout << "Cheater" << endl; // print the result
        }else{
            cout << "Innocent" << endl;
        }
        
    }
    return 0;
}
