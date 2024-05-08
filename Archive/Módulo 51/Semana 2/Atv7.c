/*
    Escreva um programa em C que pe�a ao usu�rio para digitar um n�mero e imprima a tabuada de multiplica��o desse n�mero
*/

#include <stdio.h>
#include <locale.h>

int main () {

    setlocale(LC_ALL, "Portuguese");
    int numero, resultado;

    printf("Digite um n�mero: ");
    scanf("%d", &numero);

    for(int i = 0; i <= 10; i++) {
        resultado = numero * i;
        printf("%d x %d = %d\n", i, numero, resultado);
    }

    return 0;
}