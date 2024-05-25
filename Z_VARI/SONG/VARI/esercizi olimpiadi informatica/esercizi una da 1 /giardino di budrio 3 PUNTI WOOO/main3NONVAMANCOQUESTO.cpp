#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>


using namespace std;

int pollice_verde(int N, vector<int> H){
    int max , max_idx, cont = 0;
    while(H.size() > 0){
        max = H[0], max_idx = 0;    
        //trovo indice del numero massimo
        for(int i = 1; i < H.size(); i++) if(H[i] > max ){
            max = H[i];
            max_idx = i;
        }
        //vedo se a destra del numero massimo sono piu piccoli
        int temp = 0;
        if(H[max_idx] > H[max_idx + 1] && max_idx != H.size()){
            for(int i = max_idx + 1; i < H.size();){
                if(H[i + 1] == H.back()){
                    if(H[i] > H[i + 1]){
                        H.erase(H.begin() + i);
                        H.pop_back();
                        break;
                    }
                }
                if(H[i] == H.back()){
                    H.pop_back();
                    break;
                }
                if(H[i] == H[i + 1] || H[i] < H[i + 1]){
                    H.erase(H.begin() + i);
                    break;
                }else H.erase(H.begin() + i);
            }
        }
        if(H[max_idx] > H[max_idx - 1] && max_idx != 0){
            for(int i = max_idx - 1; i < H.size() ;){
                if(H[i - 1] == H[0]){
                    if(H[i] > H[i - 1]){
                        H.erase(H.begin() + i);
                        H.erase(H.begin());
                        break;
                    }
                }
                if(H[i] == H[0]){
                    H.erase(H.begin());
                    break;
                }
                if(H[i] == H[i - 1] || H[i] < H[i - 1]){
                    H.erase(H.begin() + i);
                    break;
                }else H.erase(H.begin() + i);
            }
        }
        max = 0;
        for(int i = 0; i < H.size(); i++) if(H[i] > max ){
            max = H[i];
            max_idx = i;
        }
        H.erase(H.begin() + max_idx);
        cont++;
        if(H[0] == max && H.size() == 1) return cont;
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
