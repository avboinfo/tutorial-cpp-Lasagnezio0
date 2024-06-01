// NOTE: it is recommended to use this even if you don't understand the following code.

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
//  uncomment the following lines if you want to read/write from files
    ifstream cin("input.txt");
    ofstream cout("output.txt");

    long long A, B, T;
    cin >> A >> B >> T;

    // insert your code here
    long giorni = T/24;
    long tempo_on = B - A;
    
    long long downtime = tempo_on * giorni;
    T -= giorni * 24;
    
    T -= 24 - tempo_on;
    if(T < 0) T = 0;
    
    cout << T + downtime << endl;
    return 0;
}
