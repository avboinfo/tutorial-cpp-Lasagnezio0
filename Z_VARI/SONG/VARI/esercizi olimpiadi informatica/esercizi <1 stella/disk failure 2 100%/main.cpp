// insert brief description of the solution here
// NOTE: it is recommended to use this even if you don't understand the following code.

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
//  uncomment the following lines if you want to read/write from files
    ifstream cin("input.txt");
    ofstream cout("output.txt");

    int N, T;
    cin >> N >> T;

    vector<int> A(N), B(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i] >> B[i];
    }

    // insert your code here
    int ore, giorni = 0;
    for(int i  = 0; i < A.size() - 1 ; i++){
        ore = ((24 - B[i]) + A[i + 1]);
        if(ore >= T) break;
        giorni++;
    }
    if(giorni == N -1) giorni = -1;
    cout << giorni << endl; // print the result
    
    return 0;
}
