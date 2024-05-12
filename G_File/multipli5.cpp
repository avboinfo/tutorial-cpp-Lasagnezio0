#include <fstream>
using namespace std;

int main() {

  ifstream a("input.txt");
  ofstream b("output.txt");
    //fstream c(cazzo.txt);


  string myText;
  string citta[10];
  int cont = 0;

  while (getline (a, myText)){
    citta[cont] = myText;
    cont++;
  }

  for(int i = 0; i < 10 ;i++){
    b << "Citta numero #" << i << ": " << citta[i] << endl;
  }
}