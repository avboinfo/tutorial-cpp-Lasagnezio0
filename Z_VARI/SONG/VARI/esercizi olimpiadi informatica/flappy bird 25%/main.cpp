// NOTE: it is recommended to use this even if you don't understand the following code.

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// input data
int N;
vector<int> A, B;

int main() {
//  uncomment the following lines if you want to read/write from files
ifstream cin("input.txt");
ofstream cout("output.txt");

    cin >> N;
    A.resize(N);
    B.resize(N);
    for (int i=0; i<N; i++)
        cin >> A[i] >> B[i];

    // insert your code here
    /*for(long long i = 1; i < A.size(); i++){
        if((A[i] >= A[i - 1] && A[i] <= B[i - 1]) || (B[i] >= A[i - 1] && B[i] <= B[i - 1])){
            continue;
        }else{
            cout << "NO" << endl;
            return 0;
        }
    }*/

    int maxA = A[0], minB = B[0];
    for(int i = 1; i < A.size(); i++) if(A[i] > maxA) maxA = A[i];
    for(int i = 1; i < B.size(); i++) if(B[i] < minB) minB = B[i];

    if(maxA > minB){
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl; // print the result
    return 0;
}
