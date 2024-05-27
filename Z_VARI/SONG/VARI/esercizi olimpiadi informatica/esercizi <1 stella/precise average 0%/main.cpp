#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <limits.h>

using namespace std;

int main() {
    // uncomment the two following lines if you want to read/write from files
    ifstream cin("input.txt");
    ofstream cout("output.txt");

    int N, K;
    cin >> N >> K;
    
    vector<int> P(N);
    for (int i = 0; i < N; ++i)
        cin >> P[i];
    
    long long totalCurrentPrice = 0;
    long long totalDesiredPrice = K * N;
    long long  cont = 0;

    for (int i = 0; i < N; ++i)
        totalCurrentPrice += P[i];
    
    int ans = 0;
    if(totalCurrentPrice > totalDesiredPrice){
        for(int i = 0; i < N; i++){
            cont += P[i];
            while(P[i] > totalDesiredPrice - totalCurrentPrice && P[i] > 0){
                P[i]--;
            }
            ans++;
            totalCurrentPrice = 0;
            for (int i = 0; i < N; ++i) totalCurrentPrice += P[i];
            if(totalCurrentPrice == totalDesiredPrice - cont) break;
        }
    }else if(totalCurrentPrice < totalDesiredPrice){
        for(int i = 0; i < N; i++){
            cont += P[i];
            while(P[i] < totalDesiredPrice - totalCurrentPrice && P[i] < INT_MAX){
                P[i]++;
            }
            ans++;
            totalCurrentPrice = 0;
            for (int i = 0; i < N; ++i) totalCurrentPrice += P[i];       
            if(totalCurrentPrice + cont == totalDesiredPrice) break;
        }
    }
    
    cout << ans << endl;

    return 0;
}
