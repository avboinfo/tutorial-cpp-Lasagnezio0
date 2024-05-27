#include <string.h>
#include <assert.h>
#include <iostream>
#include <vector>
#include <cstdint>

#define MAXN 100000

using namespace std;

int zeri(int N, char S[]) {
   
    // Mettete qui il codice della soluzione
    vector<char> n;
    n.clear();
    __int128 moltiplicazione = 1;
    int cont = 0;
   
    for(int i = 0; i < N + 1; i++){
        if(S[i] != 'x' && S[i] != '\0') n.push_back(S[i]);
        else{
            string str(n.begin(), n.end());
            n.clear();

            int value = stoi(str);
            cout << value << " ";
            moltiplicazione *= value;
        }
    }
    
    while(moltiplicazione % 10 == 0){
        cont++;
        moltiplicazione /= 10;
    }
    return cont;
}


char S[MAXN + 1];

int main() {
    FILE *fr, *fw;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(1 == fscanf(fr, "%s", S));

    fprintf(fw, "%d\n", zeri(strlen(S), S));
    fclose(fr);
    fclose(fw);
    return 0;
}
