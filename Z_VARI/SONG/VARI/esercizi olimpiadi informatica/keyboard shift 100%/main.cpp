// NOTE: it is recommended to use this even if you don't understand the
// following code.

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

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
    char pezzo;
    int shift = 97;
    char lettere[26] = {'s','n','v','f','r','g','h','j','o','k','l','l','m','m','p','p','w','t','d','y','i','b','e','c','u','x'};
    for(int i = 0; i < N; i++){
        int pezzo = S[i];
        S[i] = lettere[pezzo - shift];
    }
    
    cout << S << endl; // print the result
    return 0;
}
