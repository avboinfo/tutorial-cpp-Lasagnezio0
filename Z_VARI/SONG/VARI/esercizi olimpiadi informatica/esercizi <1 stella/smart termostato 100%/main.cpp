/*
 * This template is valid both in C and in C++,
 * so you can expand it with code from both languages.
 * NOTE: it is recommended to use this even if you don't
 * understand the following code.
 */

#include <stdio.h>
#include <assert.h>

// constraints
#define MAXN 100000

// input data
int N, i;
int V[MAXN];

int main() {
//  uncomment the following lines if you want to read/write from files
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    assert(1 == scanf("%d", &N));
    for(i=0; i<N; i++)
        assert(1 == scanf("%d", &V[i]));

    // insert your code here
    int somma = V[0];
    for(int i = 1; i < N ; i++){
        if(V[i] == -1) V[i] = V[i - 1];
        somma += V[i];
    }

    printf("%d\n", somma); // print the result
    return 0;
}
