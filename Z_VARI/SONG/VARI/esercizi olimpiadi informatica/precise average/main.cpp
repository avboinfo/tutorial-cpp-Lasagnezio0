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

    for (int i = 0; i < N; ++i)
        totalCurrentPrice += P[i];
    
    int ans = 0;
    if(totalCurrentPrice > totalDesiredPrice){
        for(int i = 0; i < N; i++){
            while(P[i] > 1){
                P[i]--;
            }
            ans++;
            for (int i = 0; i < N; ++i) totalCurrentPrice += P[i];
            if(totalCurrentPrice < totalDesiredPrice){
                int diff = totalDesiredPrice - totalCurrentPrice;
                P[i] += diff;
                break;
            }else if(totalCurrentPrice == totalDesiredPrice){
                break;
            } 
        }
    }else if(totalCurrentPrice < totalDesiredPrice){
        for(int i = 0; i < N; i++){
            while(P[i] < totalDesiredPrice){
                P[i]++;
            }
            ans++;
            
            for (int i = 0; i < N; ++i) totalCurrentPrice += P[i];
            if(totalCurrentPrice > totalDesiredPrice){
                int diff = totalCurrentPrice - totalDesiredPrice;
                P[i] -= diff;
                break;
            }else if(totalCurrentPrice == totalDesiredPrice) break;
        }
    }else{
        ans = 0;
    }
    
    cout << ans << endl;

    return 0;
}
