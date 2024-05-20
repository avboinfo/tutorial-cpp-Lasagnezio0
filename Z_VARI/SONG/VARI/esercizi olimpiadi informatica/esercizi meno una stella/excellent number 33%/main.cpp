// NOTE: it is recommended to use this even if you don't understand the following code.

#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int main() {
    // uncomment the following lines if you want to read/write from files
    ifstream cin("input.txt");
    ofstream cout("output.txt");

    int N;
    cin >> N;
    
    //insert your code here
    int num = 0;
    int cont = 0;
    string n = to_string(num);
    //cout << n.size();

    for(int i = pow(10, N - 1); n.size() < N; num = 3 * i++){
        string n = to_string(num);
        cont = 0;
        for(int j = 0; j < n.size(); j++){
            if(n[j] == '1' || n[j] == '5') cont++;
        }
        if(cont == N) break;
    }
    if(cont != N) num = -1;
    cout << num << endl; // print the result
    return 0;
}
