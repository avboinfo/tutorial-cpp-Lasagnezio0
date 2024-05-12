#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

long long solve(){
    int N;
    cin >> N;
    vector<int> V(N);
    for(int &x: V){
        cin >> x;
    }

    long long val_min = V[0], val_max = V[0];
    for(int i = 1; i < N; i++){
        if(V[i] < val_min) val_min = V[i];
        if(V[i] > val_max) val_max = V[i];
    }

    return val_min * val_max;
}

int main(){
    ifstream cin("input.txt");
    ofstream cout("output.txt");
    int T;
    cin >> T;
    for (int i = 0; i < T; i++){
        cout << "Case #" << i+1 << ": " << solve() << endl;
    }
    return 0;
}
