// ESEGUIBILE SOLO IN AMBIENTI DI SVILUPPO AVENTI LA POSSIBILITà DI USARE WINDOWS.H, AD ESEMPIO CODEBLOCKS

#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <fstream>
#include <vector>

using namespace std;

struct chord{
    string nota;
    int durata;
};

struct notes{
    string name;
    float frequency;
};

notes n[] = { {"do", 261.63} , {"re", 293.66} , {"mi", 329.63} , {"fa", 349.23} , {"sol", 392} , {"la", 440} , {"si", 493.88} };

vector<chord> song;

float getFrequency(string nota){
    for(int i = 0; i < 7; i++){
        if(n[i].name == nota) return n[i].frequency;
    }
    return 200.0;
}

void readSong(string filename){
    string linea;
    char nota[4];
    int durata;
    chord c;

    ifstream f(filename);
    while (getline(f,linea)){
        sscanf(linea.c_str(),"%s %d", nota, &durata);
        c.nota = nota;
        c.durata = durata;
        song.push_back(c);
    }
    f.close();
}

void playSong(vector<chord> song){
    int lunghezza = song.size();
    for(int i = 0; i < lunghezza; i++){
        float f = getFrequency(song[i].nota);
        Beep(f, song[i].durata);
    }
}


int main()
{

    /*for(int i = 0; i < 7; i++){
        cout << n[i].name << endl;
        Beep(n[i].frequency , 500);
    }*/
    readSong("fraMartino.txt");
    cout << song.size();
    playSong(song);
    return 0;
}
