// NOTE: it is recommended to use this even if you don't understand the following code.

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    // uncomment the two following lines if you want to read/write from files
    ifstream cin("input.txt");
    ofstream cout("output.txt");

    int T;
    cin >> T;
    for (int test = 1; test <= T; ++test) {
        int N;
        cin >> N;
        
        vector<int> P(N);
        for (int i = 0; i < N; ++i)
            cin >> P[i];
        
        string ans = "";
        
        
        // INSERT YOUR CODE HERE
        long long sommaDaniel = 0;
        long long sommaAvversario = 0;

        int x = 0;
        for(int i = 0; i < N; i++){
            x = P[i];
            switch(x){
                case 1:
                    sommaDaniel += 25;
                    sommaAvversario += 18;
                    break;
                case 2:
                    sommaDaniel += 18;
                    sommaAvversario += 25;
                    break;
                case 3:
                    sommaDaniel += 15;
                    sommaAvversario += 25;
                    break;
                case 4:
                    sommaDaniel += 12;
                    sommaAvversario += 25;
                    break;
                case 5:
                    sommaDaniel += 10;
                    sommaAvversario += 25;
                    break;
                case 6:
                    sommaDaniel += 8;
                    sommaAvversario += 25;
                    break;
                case 7:
                    sommaDaniel += 6;
                    sommaAvversario += 25;
                    break;
                case 8:
                    sommaDaniel += 4;
                    sommaAvversario += 25;
                    break;
                case 9:
                    sommaDaniel += 2;
                    sommaAvversario += 25;
                    break;
                case 10:
                    sommaDaniel += 1;
                    sommaAvversario += 25;
                    break;
                default:
                    sommaDaniel += 0;
                    sommaAvversario +=25;
            }
        }
        if(sommaDaniel >= sommaAvversario) ans = "Champion";
        else ans = "Practice harder";
        
        cout << ans << endl;
    }

    return 0;
}
