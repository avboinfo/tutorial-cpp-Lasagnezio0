// NOTE: it is recommended to use this even if you don't understand the following code.

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// input data
int N;
vector<int> K;

int main() {
//  uncomment the following lines if you want to read/write from files
    ifstream cin("input.txt");
    ofstream cout("output.txt");

    cin >> N;
    K.resize(N);
    for (int i=0; i<N; i++)
        cin >> K[i];

    int cont;
    // insert your code here
    for(int i = 0; i < K.size(); i++){
        vector<char> numeri = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        cont = 0;

        for(int i = 0; numeri.size() > 0; i++){
            string numero_stringa = to_string(K[i] * 3);

            for(int j = 0; j < numero_stringa.size(); j++){
                for(int m = 0; m < numeri.size(); m++){
                    if(numero_stringa[j] == numeri[m]){
                        numeri.erase(numeri.begin() + m);
                    }
                }
            }
            cont++;
        }
        cout << cont << endl;
    }

    return 0;
}
