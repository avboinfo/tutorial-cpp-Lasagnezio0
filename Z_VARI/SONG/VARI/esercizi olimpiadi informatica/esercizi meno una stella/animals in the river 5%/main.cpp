// NOTE: it is recommended to use this even if you don't understand the following code.

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// input data
int N;
vector<int> S;

int main() {
//  uncomment the following lines if you want to read/write from files
    ifstream cin("input.txt");
    ofstream cout("output.txt");

    cin >> N;
    S.resize(N);
    for (int i=0; i<N; i++)
        cin >> S[i];

    // insert your code here
    if(N == 0){
        cout << 0 << endl;
        return 0;
    }
    if(N == 1){
        cout << 1 << endl;
        return 0;
    }
    if(N == 2){
        if(S[1] > S[0]){
            cout << 1 << endl;
            return 0;
        }
        cout << 2 << endl;
        return 0;
    }
    int check = N;
    
    for(int i = N - 1;i > 0; i--){
        for(int j = N - 2; j > 0; j--){
            if(S[j] < S[i]){
                S.erase(S.begin() + j);
                N--;
            }
        }
        if(N == check) break;
    }
    
    cout << N << endl; // print the result
    return 0;
}
