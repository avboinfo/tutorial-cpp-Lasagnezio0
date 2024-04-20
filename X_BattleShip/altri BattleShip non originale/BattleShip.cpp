/*
 * BattleShipOne - Una battaglia navale contro il computer sulla costa
 * Author: Sandro Gallo
 * Date: 4 december 2020
 * Help sui codici nella mappa: 0-empty, 1-ship, 2-bomb, 3-strike
 */

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void initialize(int v[], int l) {
    for (int i = 0; i < l; i++) v[i] = 0;
}

void show(int v[], int l) {
    for (int i = 0; i < l; i++) {
        switch (v[i]) {
        case 0: cout << "O "; break;
        case 1: cout << "O "; break;
        case 2: cout << "- "; break;
        case 3: cout << "* ";
        }
    }
    cout << endl;
}

void arrange(int v[], int l) {
    srand((unsigned int)time(NULL));
    int n = rand() % (l - 1); // elle meno uno !!!!!!
    v[n] = 1;
    v[n + 1] = 1;
}

void launch(int v[], int l) {
    int p = 0;
    while (p<1 || p>l) {
        cout << "Inserire le coordinate in cui sgangiare la bomba (1.." << l << "): ";
        cin >> p;
    }
    p--;
    if (v[p] == 0) v[p] = 2;
    if (v[p] == 1) v[p] = 3;
}

bool weWon(int v[], int l) {
    for (int i = 0; i < l; i++) {
        if (v[i] == 1) return false;
    }
    return true;
}

int main()
{
    cout << "Programma BattleShipOne in esecuzione" << endl;
    int num_bomb = 0;
    const int MAPLENGTH = 10;
    int map[MAPLENGTH];
    initialize(map, MAPLENGTH);
    arrange(map, MAPLENGTH);
    show(map, MAPLENGTH);
    while (true) {
        num_bomb++;
        launch(map, MAPLENGTH);
        show(map, MAPLENGTH);
        if (weWon(map, MAPLENGTH)) break;
    }
    if (num_bomb <= 3) cout << "Complimenti";
    else if (num_bomb <= 5) cout << "Bravino";
    else if (num_bomb <= 7) cout << "Accidenti";
    cout << " hai distrutto la flotta nemica utilizzando " << num_bomb << " bombe." << endl;
    return 0;
}

