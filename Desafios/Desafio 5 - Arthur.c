/* 
    Desenvolver um algoritmo em C que  pe�a ao usu�rio para inserir um n�mero inteiro.
    Seu programa dever� somar seus d�gitos desse n�mero.
    Por exemplo, se o n�mero for 19, dever� somar 1+9. Se o n�mero for 5, dever� somar 0+5. Se o n�mero for 2023, dever� somar 2+0+2+3.
*/

#include <stdio.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "portuguese");

    char numeros[100];
    int soma = 0;

    printf("Insira um n�mero inteiro:\n");
    scanf("%s", &numeros);

    for (int i = 0; i < strlen(numeros); i++) {
        soma += (numeros[i] - '0');
    }

    printf("\nResultado: %d da soma dos d�gitos: %s\n", soma, numeros);


    return 0;
}