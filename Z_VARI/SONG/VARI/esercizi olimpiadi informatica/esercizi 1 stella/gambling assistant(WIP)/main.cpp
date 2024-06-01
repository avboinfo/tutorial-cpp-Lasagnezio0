#include <stdio.h>
#include <vector>
#include <assert.h>
#include <iostream> // Per cout

using namespace std;

int N, K;
vector<int> mano;
int somma;

int process(int C) {
    // inserisci qui il tuo codice
    if(mano.size() < K) {
        mano.push_back(C);
        somma += C;
        cout << C << endl;
    }
    else {
        int min = mano[0];
        int min_idx = 0;
        for (int i = 1; i < K; i++) {
            if (mano[i] < min) {
                min = mano[i];
                min_idx = i;
            } 
        }
        if(min < C) {
            somma -= min;
            somma += C;
            mano[min_idx] = C;
        }
    }
    return somma;
}

int main() {
    FILE *fr, *fw;
    int C, i;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(2 == fscanf(fr, "%d %d", &N, &K));
    for(i = 0; i < N; i++) {
        assert(1 == fscanf(fr, "%d", &C));
        fprintf(fw, "%d ", process(C));
    }
    fprintf(fw, "\n");
    fclose(fr);
    fclose(fw);
    return 0;
}
