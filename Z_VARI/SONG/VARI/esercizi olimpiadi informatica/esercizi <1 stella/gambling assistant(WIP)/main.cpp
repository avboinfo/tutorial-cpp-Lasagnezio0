#include <stdio.h>
#include <vector>
#include <assert.h>

int N, K;

int round(int C) {
    // insert your code here
    vector<int> mano[K - 1];
    
    for(int i = 0; i < K; i++){
        if(mano[i] == 0){
            mano[i] = C;
            break;
        }
    }
    return 42;
}

using namespace std;

int main() {
    FILE *fr, *fw;
    int C, i;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(2 == fscanf(fr, "%d %d", &N, &K));
    for(i=0; i<N; i++) {
        assert(1 == fscanf(fr, "%d", &C));
        fprintf(fw, "%d ", round(C));
    }
    fprintf(fw, "\n");
    fclose(fr);
    fclose(fw);
    return 0;
}
