#include <algorithm>
#include <fstream>
#include <vector>
#include <iostream>

using namespace std;

int main(){

    ifstream cin("input.txt");
    ofstream cout("output.txt");

    int N, b;
    cin >> N >> b;
    vector<int> piatti(N);
    vector<int> somme(N);

    for (int i = 0; i < N; ++i) {
        cin >> piatti[i];
    }

    sort(piatti.begin(), piatti.end(),greater<int>());
    int temp = b;

    //I PIATTI SONO SOLO COPPIE, PARTIRE DA I E METTERLO B -= I, ANDARE POI NELL ALTRO FOR E PARTIRE
    //SEMPRE DAL PIU GRANDE AL PIU PICCOLO PER AVERE LA SPESA PIU GRANDE
    //METTERE I RISULTATI IN UN VECTOR DI VECTOR 
    // CONFRONTARLI DOPO
    for(int i = 0; piatti.size() != 0  && i < N; i++){
        int somma = piatti[i];
        for(int j = 0; j < N; j++){
            if((b - piatti[j]) > 0); 
        }
    }
}