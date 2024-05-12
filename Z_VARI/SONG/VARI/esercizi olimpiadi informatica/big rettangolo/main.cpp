// NOTE: it is recommended to use this even if you don't understand the following code.

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // uncomment the two following lines if you want to read/write from files
    ifstream cin("input.txt");
    ofstream cout("output.txt");

    int N;
    cin >> N;
    
    vector<long> S(N);
    for (int i = 0; i < N; ++i)
        cin >> S[i];
    
    long long A = 0;
    
    
    // INSERT YOUR CODE HERE
    long dupl1 = 0, dupl2 = 0;
    if(S[0] == S[1] && S[0] == S[2] && S[0] == S[3]){
        A = (long long)S[0] * S[1];
        cout << A << endl;
        return 0;
    }

    std::sort(S.begin(), S.end());
    for(int i = N - 1; i > 0; i--){
        if(S[i] == S[i - 1]){
            dupl1 = S[i];
            S.erase(S.begin() + i);
            S.erase(S.begin() + i - 1);
            N = N -2;
            break;
        }
    }

    for(int i = N - 1; i > 0; i--){
        if(S[i] == S[i - 1]){
            dupl2 = S[i];
            S.erase(S.begin() + i);
            S.erase(S.begin() + i - 1);
            break;
        }
    }
    if(dupl2 == S[S.size()]) dupl2 = 0;


    A = (long long)dupl1 * dupl2;
    cout << A << endl;

    return 0;
}
