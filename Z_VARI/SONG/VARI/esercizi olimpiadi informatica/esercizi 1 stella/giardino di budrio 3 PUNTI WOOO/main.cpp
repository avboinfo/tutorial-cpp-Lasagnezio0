#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

int pollice_verde(int N, vector<int> H){
    int cont = 0, max = 0, max_idx, left_idx = 0, right_idx = 0;
    for(int i = 0; H.size() > 0; i++){
        max = H[0];
        max_idx = 0;
        for(int j = 1; j < H.size(); j++){
            if(H[j] > max){
                max = H[j];
                max_idx = j;
            } 
        }
        left_idx = max_idx;
        for(int j = 1; H.size() > 0;j++){
            if(H[0] == H[max_idx]) break;
            if(H[max_idx - j] < H[max_idx - j + 1] && H[max_idx - j] != H[max_idx - j + 1] && max_idx - j > 0){
                left_idx = max_idx - j;
            }else{
                break;
            }
        }
        right_idx = max_idx;
        for(int j = 1; H.size() > 0;j++){
            if((H[H.size()] == H[max_idx])) break;
            if(H[max_idx + j] < H[max_idx + j - 1]  && H[max_idx + j] != H[max_idx + j - 1]){
                right_idx = max_idx + j;
            }else{
                break;
            }
        }
        cont++;
        if (left_idx >= 0 && right_idx < H.size() && left_idx <= right_idx) {
            H.erase(H.begin() + left_idx, H.begin() + right_idx + 1);
        }else{
            H.erase(H.begin() + left_idx, H.begin() + right_idx);
        }
    }
    if(H.size() == 1) cont++;
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
