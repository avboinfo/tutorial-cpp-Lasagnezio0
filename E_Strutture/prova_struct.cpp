/*
** prova_struct.cpp
** Author: IAV 3CIN
** 26/02/2024
*/

#include <iostream>

using namespace std;

/* Il tipo di dato "struct" serve per memorizzare dati di tipi uguali o diversi
** nella stessa struttura, per poter accedere a ciascuno dei membri 
** attraverso il nome unico della struttura.
*/

struct persona
{
    string nome;
    int eta;
};

typedef struct{
  int uno;
  int due;
}COPPIA;

// per dare nome a strutture, molto utile 
//typedef int numeroanni;


int main()
{
  struct persona gigi, gigietto;

 // numeroanni piccolo = 6;

  COPPIA coppia_eta;
  gigi.nome = "Luigi";
  coppia_eta.uno = 18;
  gigi.eta = coppia_eta.uno;

  gigietto.nome = "Luigino";
  coppia_eta.due = 7;
  gigietto.eta = coppia_eta.due;
  
  cout << "Gigi si chiama " << gigi.nome << " ed ha " << gigi.eta << " anni" << endl;
  cout << "Gigietto si chiama " << gigietto.nome << " ed ha " << gigietto.eta << " anni" << endl;

  
  return 0;
}
