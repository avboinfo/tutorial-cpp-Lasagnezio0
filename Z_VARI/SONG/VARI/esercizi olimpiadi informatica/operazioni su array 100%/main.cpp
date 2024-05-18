#include <iostream>
#include <fstream>

using namespace std;

int main(){
    ifstream cin("input.txt");
    ofstream cout("output.txt");
    
    int N = 0;
    cin >> N;
    int v[N];
    
    for(int i = 0; i < N; i++){
        cin >> v[i];
    }
    float somma = 0;

    for(int i = 0; i < N; i++) somma += v[i];
    float media = somma/N; 
    
    cout << somma << " ";
    cout << media << endl;
}