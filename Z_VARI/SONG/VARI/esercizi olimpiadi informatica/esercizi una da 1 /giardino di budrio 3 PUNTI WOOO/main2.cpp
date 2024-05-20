#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

int pollice_verde(int N, vector<int> H){
    int cont = 0, numero_rotazioni;
    if(H.size() == 1){
        cont++;
        return cont;
    }
    while(H.size() > 0){
        numero_rotazioni = 0;
        //trovo il massimo
        double max = *max_element(H.begin(), H.end());
        //cosa tattica
        if(H.size() == 2){
            cont++;
            return cont;
        }
        if(H.size() == 3){
            if(H[0] > H[1] && H[1] > H[2] || H[2] > H[1] && H[1] > H[0]){
                cont++;
                return cont;
            }else if(H[0] == H[1] && H[0] == H[2]){
                cont += 3;
                return cont;
            }else{
                cont += 2;
                return cont;
            }
        }
        //ruoto il vettore finchè il massimo non è al primo posto
        while(H[0] != max){
            rotate(H.begin(), H.begin()+1, H.end());
            numero_rotazioni++;
        }
        int temp = H[0];
        //cancello tutti i numeri minori 
        for(int i = 0; i < H.size() - 1;){
            if(H[i] > H[i + 1]) H.erase(H.begin() + i);
            else{
                H.erase(H.begin());
                break;
            }
        }
        //cancello i numeri spostati che devono essere cancellati (spero)
        for(int i = H.size();i > H.size() - numero_rotazioni;i--){
            if(H[i] > H[i - 1]) H.erase(H.begin() + i);
            else break;
        }
        if(H.size() == 1){
            if(temp > H[0]) H.clear();
        }
        cont++;
    }
    return cont;
}


int main() {
    
    ifstream cin("input.txt");
    ofstream cout("output.txt");
    int N;
    cin >> N;
    vector<int> H(N);
    for (int& i : H)
        cin >> i;
    cout << pollice_verde(N, H) << '\n';
    return 0;
}
