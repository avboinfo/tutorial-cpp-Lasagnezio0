// NOTE: it is recommended to use this even if you don't understand the following code.

#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

// input data
int N;
string S;

int main() {
//  uncomment the following lines if you want to read/write from files
    ifstream cin("input.txt");
    ofstream cout("output.txt");

    cin >> N;
    cin >> S;

    // insert your code here
    int passi_finali = 0;
    for(int i = 0; i < N; i++){
        if(S[i] == 'L') passi_finali--;
        if(S[i] == 'R') passi_finali++;
    }
    if(N = 0) passi_finali = 0;
    if(passi_finali < 0) passi_finali = abs(passi_finali);
    cout << passi_finali << endl; // print the result
    return 0;
}
