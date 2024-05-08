/*
    Escreva um programa em C que encontre o fatorial de um n�mero fornecido pelo us�rio
*/

#include <stdio.h>
#include <locale.h>

int main () {

    setlocale(LC_ALL, "Portuguese");
    int numero, i;

    printf("Informe um n�mero inteiro: ");
    scanf("%d", &numero);

    // O n�mero multiplicado por seus antecessores
    for (i = numero-1; i > 0; i--) {
        numero *= i;
        printf("%d * %d = %d\n", numero/i, i, numero);
    }

    return 0;
}