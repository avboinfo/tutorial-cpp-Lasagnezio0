#include <stdio.h>
#include <assert.h>

//fatto durante sistemi e reti troppo forte

int compra(int N, int M, int A, int B) {
    // Mettete qui il codice della soluzione
    int carnet_op = 0;
    bool real = false;
    int costo = 0;

    if(A * M < B){
        real = true;
        carnet_op = A * M;
    }

    while(N >= M){
        if(real == true){
            N -= M;
            costo += carnet_op;
        }else{
            N -= M;
            costo += B;
        }
    }

    while(N > 0){
        if(B < A * N){
            costo += B;
            break;
        }else{
            N -= 1;
            costo += A;
        }
    }
    return costo;
}

int main() {
    FILE *fr, *fw;
    int N, M, A, B;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");

    assert(4 == fscanf(fr, "%d%d%d%d", &N, &M, &A, &B));

    fprintf(fw, "%d\n", compra(N, M, A, B));
    fclose(fr);
    fclose(fw);
    return 0;
}
