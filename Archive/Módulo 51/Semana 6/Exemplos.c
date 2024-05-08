#include <stdio.h>
#include <locale.h>

void minhaFuncao (int *a, int *b) {
    int resultado;

    resultado = *a + *b;

    printf ("%d\n", resultado);
}

int main (void) {
    setlocale(LC_ALL, "portuguese");

    // Exemplo 1
    printf("Exemplo 1:\n");
    int A, B;
    A = 10;
    B = 20;
    
    minhaFuncao(&A, &B);

    // Exemplo 2
    int vetor[3] = {1, 2, 3};
    int *ponteiro;

    printf("\nExemplo 2:\n");
    ponteiro = vetor;
    printf("Endere�o indice 0: %d\n", *ponteiro);
    ponteiro++;
    printf("Endere�o indice 1: %d\n", *ponteiro);
    ponteiro++;
    printf("Endere�o indice 2: %d\n", *ponteiro);
    //ponteiro++;
    //printf("Endere�o 4bytes depois: %d\n", *ponteiro);

    // Exemplo 3
    int x, *p;
    x = 10;
    p = &x;

    printf("\nExemplo 3:\n");
    printf("Valor armazenado em p: %p\n", p); // Valor armazenado em P: Endere�o de mem�ria hexadecimal A
    printf("Endere�o de p: %p\n", &p); // Endere�o de p > Endere�o de mem�ria hexadecimal B (endere�o do ponteiro em si)
    printf("Endere�o de x: %p\n", &x); // Endere�o de x > Endere�o de mem�ria hexadecimal A
    printf("Valor armazenado em X: %d\n", x); // Valor armazenado em X: 10
    printf("Valor armazenado no endere�o de mem�ria que est� em p: %d\n", *p); // Valor armazenado no endere�o de mem�ria que est� em p > X: 10

    // Exemplo 4
    printf("\nExemplo 4:\n");
    for (int i = 0; i < 3; i++) {
        ponteiro = &vetor[i];

        printf("Indice %d: %p\n", i, ponteiro);
    } 

    return 0;
}